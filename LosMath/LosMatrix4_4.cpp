//
//  LosMatrix4_4.cpp
//  C_Plus_Plus_Engine
//
//  Created by Сергей Лоскутников on 31/10/2016.
//  Copyright © 2016 sergey.loscutnikov.phoridaeentertainment. All rights reserved.
//


#include "LosMatrix4_4.hpp"
#include "MatAndVectOperators.hpp"




  /*
      [0][0]  [1][0]  [2][0]  [3][0]
      [0][1]  [1][1]  [2][1]  [3][1]
      [0][2]  [1][2]  [2][2]  [3][2]
      [0][3]  [1][3]  [2][3]  [3][3]
   
   */



LosMatrix4_4::LosMatrix4_4()
{
    for( int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            elements[i][j] = 0.0f;
        }
    }
    
}


LosMatrix4_4::~LosMatrix4_4()
{
    
}

LosMatrix4_4::LosMatrix4_4(LosVector3& vec1, LosVector3& vec2, LosVector3& vec3)
{
    this->elements[0][0] = vec1.x;   this->elements[1][0] = vec1.y;   this->elements[2][0] = vec1.z;
    this->elements[0][1] = vec2.x;   this->elements[1][1] = vec2.y;   this->elements[2][1] = vec2.z;
    this->elements[0][2] = vec3.x;   this->elements[1][2] = vec3.y;   this->elements[2][2] = vec3.z;
    this->elements[0][3] = 0.0f;     this->elements[1][3] = 0.0f;     this->elements[2][3] = 0.0f;
    
    this->elements[3][0] = 0.0f;
    this->elements[3][1] = 0.0f;
    this->elements[3][2] = 0.0f;
    this->elements[3][3] = 1.0f;
}


LosMatrix4_4::LosMatrix4_4(LosVector3& vec1, LosVector3& vec2, LosVector3& vec3, LosVector3& vec4)
{
    this->elements[0][0] = vec1.x;   this->elements[1][0] = vec1.y;   this->elements[2][0] = vec1.z;
    this->elements[0][1] = vec2.x;   this->elements[1][1] = vec2.y;   this->elements[2][1] = vec2.z;
    this->elements[0][2] = vec3.x;   this->elements[1][2] = vec3.y;   this->elements[2][2] = vec3.z;
    this->elements[0][3] = vec4.x;   this->elements[1][3] = vec4.y;   this->elements[2][3] = vec4.z;
    
    this->elements[3][0] = 0.0f;
    this->elements[3][1] = 0.0f;
    this->elements[3][2] = 0.0f;
    this->elements[3][3] = 1.0f;
}


LosMatrix4_4::LosMatrix4_4(LosVector4& vec1, LosVector4& vec2, LosVector4& vec3, LosVector4& vec4)
{
    this->elements[0][0] = vec1.x;   this->elements[1][0] = vec1.y;   this->elements[2][0] = vec1.z; this->elements[3][0] = vec1.w;
    this->elements[0][1] = vec2.x;   this->elements[1][1] = vec2.y;   this->elements[2][1] = vec2.z;   this->elements[3][1] = vec2.w;
    this->elements[0][2] = vec3.x;   this->elements[1][2] = vec3.y;   this->elements[2][2] = vec3.z;    this->elements[3][2] = vec3.w;
    this->elements[0][3] = vec4.x;   this->elements[1][3] = vec4.y;   this->elements[2][3] = vec4.z;     this->elements[3][3] = vec4.w;
    

}



void LosMatrix4_4::ScaleLos(LosVector3 vecScale)
{
    LosMatrix4_4 iden = identity();
    
    iden.elements[0][0] = vecScale.x;
    iden.elements[1][1] = vecScale.y;
    iden.elements[2][2] = vecScale.z;
    
    *this = *this * iden;
    
}

void LosMatrix4_4::Transposition(LosVector3 vecTransposition)
{
       LosMatrix4_4 iden = identity();
    
    iden.elements[3][0] = vecTransposition.x;
    iden.elements[3][1] = vecTransposition.y;
    iden.elements[3][2] = vecTransposition.z;
    
    *this = *this * iden;
    
}

void LosMatrix4_4::RotateWithOurAxilar(LosVector3 vec)
{
    LosMatrix4_4 losBack = identity();
    losBack.Transposition(LosVector3(-vec.x, -vec.y, -vec.z));
    
    LosMatrix4_4 losBack1 = identity();
    losBack1.rotateLosY(180);
    
       LosMatrix4_4 losBack2 = identity();
       losBack.Transposition(LosVector3(vec.x, vec.y, vec.z));
    
    LosMatrix4_4 finalBack = losBack * losBack1 * losBack2;
    
    *this = *this * finalBack;
}



void LosMatrix4_4::rotateLosX(float angle)
{
    LosMatrix4_4 rotateIdent = identity();

    rotateIdent.elements[1][1] =   cosf(degrees_to_radian(angle));
    rotateIdent.elements[2][1] =   sinf(degrees_to_radian(angle));
    rotateIdent.elements[1][2] =  -sinf(degrees_to_radian(angle));
    rotateIdent.elements[2][2] =   cosf(degrees_to_radian(angle));

    *this = *this * rotateIdent;

}

void LosMatrix4_4::rotateLosY(float angle)
{
    LosMatrix4_4 rotateIdent = identity();

    rotateIdent.elements[0][0] =   cosf(degrees_to_radian(angle));
    rotateIdent.elements[2][0] =  -sinf(degrees_to_radian(angle));
    rotateIdent.elements[0][2] =   sinf(degrees_to_radian(angle));
    rotateIdent.elements[2][2] =   cosf(degrees_to_radian(angle));

    *this = *this * rotateIdent;
}



void LosMatrix4_4::rotateLosZ(float angle)
{
    
    LosMatrix4_4 rotateIdent = identity();
    
    rotateIdent.elements[0][0] =   cosf(degrees_to_radian(angle));
    rotateIdent.elements[1][0] =   sinf(degrees_to_radian(angle));
    rotateIdent.elements[0][1] =  -sinf(degrees_to_radian(angle));
    rotateIdent.elements[1][1] =   cosf(degrees_to_radian(angle));
    
    *this = *this * rotateIdent;
    
}














