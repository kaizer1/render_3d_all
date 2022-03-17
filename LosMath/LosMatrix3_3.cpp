//
//  LosMatrix3_3.cpp
//  C_Plus_Plus_Engine
//
//  Created by Сергей Лоскутников on 31/10/2016.
//  Copyright © 2016 sergey.loscutnikov.phoridaeentertainment. All rights reserved.
//

#include "LosMatrix3_3.hpp"

#ifdef _WIN32
#define _USE_MATH_DEFINES
#include <math.h>
#include <limits.h>
#include <float.h>
//#define __FLT_EPSILON__ = FLT_EPSILON
#else
#include <math.h>
#endif // _WIN32



/*
 [0][0]  [1][0]  [2][0]
 [0][1]  [1][1]  [2][1]
 [0][2]  [1][2]  [2][2]
 */


//quat getRot() const {
//    float t, s;
//    t = 1.0f + e00 + e11 + e22;
//    if (t > EPS) {
//        s = 0.5f / sqrtf(t);
//        return quat((e21 - e12) * s, (e02 - e20) * s, (e10 - e01) * s, 0.25f / s);
//    } else
//        if (e00 > e11 && e00 > e22) {
//            s = 0.5f / sqrtf(1.0f + e00 - e11 - e22);
//            return quat(0.25f / s, (e01 + e10) * s, (e02 + e20) * s, (e21 - e12) * s);
//        } else
//            if (e11 > e22) {
//                s = 0.5f / sqrtf(1.0f - e00 + e11 - e22);
//                return quat((e01 + e10) * s, 0.25f / s, (e12 + e21) * s, (e02 - e20) * s);
//            } else {
//                s = 0.5f / sqrtf(1.0f - e00 - e11 + e22);
//                return quat((e02 + e20) * s, (e12 + e21) * s, 0.25f / s, (e10 - e01) * s);
//            }
//}


LosMatrix3_3::LosMatrix3_3()
{
    
}


LosMatrix3_3::~LosMatrix3_3()
{
    
}

LosMatrix3_3::LosMatrix3_3(LosVector3 x, LosVector3 y, LosVector3 z)
{
    this->elements[0][0] = x.x;    this->elements[1][0] = x.y;   this->elements[2][0] = x.z;
    this->elements[0][1] = y.x;    this->elements[1][1] = y.y;   this->elements[2][1] = y.z;
    this->elements[0][2] = z.x;    this->elements[1][2] = z.y;   this->elements[2][2] = z.z;
}


LosQuaternion getRotationMatrix(LosMatrix3_3& rotMat) 
{
    float t,s;
    
    t = 1.0f + rotMat.elements[0][0] + rotMat.elements[1][1] + rotMat.elements[2][2];
    
    if(t > FLT_EPSILON)
    {
        s = 0.5f / sqrtf(t);
        return LosQuaternion((rotMat.elements[2][1] - rotMat.elements[1][2]) * s,
                             (rotMat.elements[0][2] - rotMat.elements[2][0]) * s,
                             (rotMat.elements[1][0] - rotMat.elements[0][1]) * s,
                             0.25f / s);
    }
    else
    {
        if(rotMat.elements[0][0] > rotMat.elements[1][1] &&
           rotMat.elements[0][0] > rotMat.elements[2][2])
        {
            s = 0.5f / sqrtf(1.0f + rotMat.elements[0][0] - rotMat.elements[1][1] - rotMat.elements[2][2]);
            return LosQuaternion(0.25f / s, (rotMat.elements[0][1] + rotMat.elements[1][0]) * s,
                                 (rotMat.elements[0][2] + rotMat.elements[2][0]) * s,
                                 (rotMat.elements[2][1] - rotMat.elements[1][2]) * s);
        }
        else if(rotMat.elements[1][1] > rotMat.elements[2][2])
        {
            s = 0.5f / sqrtf(1.0f - rotMat.elements[0][0] + rotMat.elements[1][1] - rotMat.elements[2][2]);
            return  LosQuaternion( (rotMat.elements[0][1] + rotMat.elements[1][0]) * s,
                                   0.25f / s,
                                   (rotMat.elements[1][2] + rotMat.elements[2][1]) * s,
                                   (rotMat.elements[0][2] - rotMat.elements[2][0]) * s);
        }
        else
        {
            s = 0.5f / sqrtf(1.0f - rotMat.elements[0][0] - rotMat.elements[1][1] + rotMat.elements[2][2]);
            return LosQuaternion( (rotMat.elements[0][2] + rotMat.elements[2][0]) * s,
                                  (rotMat.elements[1][2] + rotMat.elements[2][1]) * s,
                                  0.25f / s,
                                  (rotMat.elements[1][0] - rotMat.elements[0][1]) * s);
        }
    }
}


void LosMatrix3_3::rotateLosX(float angle)
{
    LosMatrix3_3 rotateIdent = ident();
    
    rotateIdent.elements[1][1] =   cosf(degrees_to_radian(angle));
    rotateIdent.elements[2][1] =   sinf(degrees_to_radian(angle));
    rotateIdent.elements[1][2] =  -sinf(degrees_to_radian(angle));
    rotateIdent.elements[2][2] =   cosf(degrees_to_radian(angle));
    
    *this = *this * rotateIdent;}

void LosMatrix3_3::rotateLosY(float angle)
{
    LosMatrix3_3 rotateIdent = ident();
    
    rotateIdent.elements[0][0] =   cosf(degrees_to_radian(angle));
    rotateIdent.elements[2][0] =  -sinf(degrees_to_radian(angle));
    rotateIdent.elements[0][2] =   sinf(degrees_to_radian(angle));
    rotateIdent.elements[2][2] =   cosf(degrees_to_radian(angle));
    
    *this = *this * rotateIdent;
}


void LosMatrix3_3::rotateLosZ(float angle)
{
    LosMatrix3_3 rotateIdent = ident();
    
    rotateIdent.elements[0][0] =   cosf(degrees_to_radian(angle));
    rotateIdent.elements[1][0] =   sinf(degrees_to_radian(angle));
    rotateIdent.elements[0][1] =  -sinf(degrees_to_radian(angle));
    rotateIdent.elements[1][1] =   cosf(degrees_to_radian(angle));
    
    *this = *this * rotateIdent;
}


LosMatrix3_3 LosMatrix3_3::ident()
{
    LosMatrix3_3 newM;
    
    for (int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j)
            newM.elements[i][j] = 0.0f;
     }
    
     newM.elements[0][0] = 1.0f;
     newM.elements[1][1] = 1.0f;
     newM.elements[2][2] = 1.0f;
    
    return newM;
}


double LosMatrix3_3::degrees_to_radian(double deg)
{
    
    return deg * M_PI/180.0;
}


LosMatrix3_3 LosMatrix3_3::operator*(LosMatrix3_3& lMat)
{
    LosMatrix3_3 returnM;
    
    /*
     [0][0]  [1][0]  [2][0]
     [0][1]  [1][1]  [2][1]
     [0][2]  [1][2]  [2][2]
     */
    
    returnM.elements[0][0] = this->elements[0][0] * lMat.elements[0][0] + this->elements[1][0] * lMat.elements[0][1] + this->elements[2][0] * lMat.elements[0][2];
    
    returnM.elements[1][0] = this->elements[0][0] * lMat.elements[1][0] + this->elements[1][0] * lMat.elements[1][1] + this->elements[2][0] * lMat.elements[1][2];
    
    returnM.elements[2][0] = this->elements[0][0] * lMat.elements[2][0] + this->elements[1][0] * lMat.elements[2][1] + this->elements[2][0] * lMat.elements[2][2];
    
    
    returnM.elements[0][1] = this->elements[0][1] * lMat.elements[0][0] + this->elements[1][1] * lMat.elements[0][1] + this->elements[2][1] * lMat.elements[0][2];
    
    returnM.elements[1][1] = this->elements[0][1] * lMat.elements[1][0] + this->elements[1][1] * lMat.elements[1][1] + this->elements[2][1] * lMat.elements[1][2];
    
    returnM.elements[2][1] = this->elements[0][1] * lMat.elements[2][0] + this->elements[1][1] * lMat.elements[2][1] + this->elements[2][1] * lMat.elements[2][2];
    
    
    returnM.elements[0][2] = this->elements[0][2] * lMat.elements[0][0] + this->elements[1][2] * lMat.elements[0][1] + this->elements[2][2] * lMat.elements[0][2];
    
    returnM.elements[1][2] = this->elements[0][2] * lMat.elements[1][0] + this->elements[1][2] * lMat.elements[1][1] + this->elements[2][2] * lMat.elements[1][2];
    
    returnM.elements[2][2] = this->elements[0][2] * lMat.elements[2][0] + this->elements[1][2] * lMat.elements[2][1] + this->elements[2][2] * lMat.elements[2][2];
    
    
    return returnM;
}


void LosMatrix3_3::retuIden()
{
    *this = ident();
   
}





























