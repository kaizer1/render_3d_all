//
//  MatAndVectOperators.cpp
//  C_Plus_Plus_Engine
//
//  Created by Сергей Лоскутников on 01/11/2016.
//  Copyright © 2016 sergey.loscutnikov.phoridaeentertainment. All rights reserved.
//

#include "MatAndVectOperators.hpp"
#include <math.h>
#include "LosMatrix3_3.hpp"
//#include "loglog.h"

//#include <arm_neon.h>


LosMatrix4_4 identity()
{
    
    LosMatrix4_4 backMatrix;
    
    backMatrix.elements[0][0] = 1.0f;
    backMatrix.elements[0][1] = 0.0f;
    backMatrix.elements[0][2] = 0.0f;
    backMatrix.elements[0][3] = 0.0f;
    backMatrix.elements[1][0] = 0.0f;
    backMatrix.elements[1][1] = 1.0f;
    backMatrix.elements[1][2] = 0.0f;
    backMatrix.elements[1][3] = 0.0f;
    backMatrix.elements[2][0] = 0.0f;
    backMatrix.elements[2][1] = 0.0f;
    backMatrix.elements[2][2] = 1.0f;
    backMatrix.elements[2][3] = 0.0f;
    backMatrix.elements[3][0] = 0.0f;
    backMatrix.elements[3][1] = 0.0f;
    backMatrix.elements[3][2] = 0.0f;
    backMatrix.elements[3][3] = 1.0f;

    //logInfo("  my matrix LOS_NEON = %d and secondNeon == %d GOI == %d  awb = %d\n", simpleNeon, secondNeon, goi, awd);

    return backMatrix;
    
}



LosMatrix4_4 perspectiveLosRithg(float FOV, float aspect, float near, float far)
{
    float fovPreFinal = static_cast<float>(FOV * (3.14/180));

    float ymax = static_cast<float>(near * tan(fovPreFinal * 0.5));
    float ymin = -ymax;

    float  xmin = ymin * aspect;
    float  xmax = ymax * aspect;
    //                l      r    b      t
// return frustum(M, xmin, xmax, ymin, ymax, n, f);
//    float f = tan(fovPreFinal/2);
//    float n = 1.0f / (near - far);
    LosMatrix4_4 projectionMatrix = identity();

    //projectionMatrix.elements[0][0] = f/(aspect);  // los build
    projectionMatrix.elements[0][0] = static_cast<float> ((2.0 * near) / (xmax - xmin));
    projectionMatrix.elements[0][1] = 0.0f;
    projectionMatrix.elements[0][2] = 0.0f;
    projectionMatrix.elements[0][3] = 0.0f;

    projectionMatrix.elements[1][0] = 0.0f;
    projectionMatrix.elements[1][1] = static_cast<float>((2.0) * near / (ymax - ymin));
    projectionMatrix.elements[1][2] = 0.0f;
    projectionMatrix.elements[1][3] = 0.0f;

    projectionMatrix.elements[2][0] = (xmax + xmin) / (xmax - xmin);       // was 0.0f
    projectionMatrix.elements[2][1] = (ymax + ymin) / (ymax - ymin);       // was 0.0f
    projectionMatrix.elements[2][2] = -(far + near)/(far-near);
    projectionMatrix.elements[2][3] = -1.0f;

    projectionMatrix.elements[3][0] = 0.0f;
    projectionMatrix.elements[3][1] = 0.0f;
    projectionMatrix.elements[3][2] = -(2.0f * far * near)/(far-near);
    projectionMatrix.elements[3][3] = 0.0f;
    return projectionMatrix;
}


LosMatrix4_4 LookAt_RightLos(LosVector3 eye, LosVector3 center, LosVector3 up, LosMatrix4_4& mat)
{
    
    LosVector3 f,s,u;
    
    f = center - eye;
    f.normalized();   // my f theis view
    
    s = f;
    s.cross(up);
    s.normalized();  // my s theis right
    
    u = s;
    u.cross(f);     // my u theis viewUp
    
    LosMatrix4_4 backMatrix = identity();
    
    backMatrix.elements[0][0] = s.x;
    backMatrix.elements[1][0] = s.y;
    backMatrix.elements[2][0] = s.z;
    
    backMatrix.elements[0][1] = u.x;
    backMatrix.elements[1][1] = u.y;
    backMatrix.elements[2][1] = u.z;
    
    backMatrix.elements[0][2] = -f.x;
    backMatrix.elements[1][2] = -f.y;
    backMatrix.elements[2][2] = -f.z;
    
    backMatrix.elements[3][0] = -s.dot(eye);
    backMatrix.elements[3][1] = -u.dot(eye);
    backMatrix.elements[3][2] = f.dot(eye);
    
    backMatrix.elements[0][3] = 0.0f;
    backMatrix.elements[1][3] = 0.0f;
    backMatrix.elements[2][3] = 0.0f;
    backMatrix.elements[3][3] = 1.0f;
    
    
    LosMatrix3_3 losMatrix;
    
    losMatrix.elements[0][0] = s.x;
    losMatrix.elements[0][1] = s.y;
    losMatrix.elements[0][2] = s.z;
    
    losMatrix.elements[1][0] = u.x;
    losMatrix.elements[1][1] = u.y;
    losMatrix.elements[1][2] = u.z;
                                                                                
    losMatrix.elements[2][0] = -f.x;
    losMatrix.elements[2][1] = -f.y;
    losMatrix.elements[2][2] = -f.z;
    
    
    mat.elements[0][0] = losMatrix.elements[0][0];
    mat.elements[0][1] = losMatrix.elements[0][1];
    mat.elements[0][2] = losMatrix.elements[0][2];
    mat.elements[0][3] = 0.0f;                          // ???  was 0 and (0,3) = eye.x
    mat.elements[1][0] = losMatrix.elements[1][0];
    mat.elements[1][1] = losMatrix.elements[1][1];
    mat.elements[1][2] = losMatrix.elements[1][2];
    mat.elements[1][3] = 0.0f;                         // ??? example Math essentions 08-Picking
    mat.elements[2][0] = losMatrix.elements[2][0];
    mat.elements[2][1] = losMatrix.elements[2][1];
    mat.elements[2][2] = losMatrix.elements[2][2];
    mat.elements[2][3] = 0.0f;                        // ???  // correct I corrected
    mat.elements[3][0] = eye.x;
    mat.elements[3][1] = eye.y;
    mat.elements[3][2] = eye.z;
    mat.elements[3][3] = 1;
    
    
    return backMatrix;
    
}

void losSeeMatrixElements(LosMatrix4_4 mat)
{
    for(int i= 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
          //  logInfo(" my [%d][%d] element == %f \n", i, j, mat.elements[i][j]);
        }
    }
}



LosMatrix4_4 operator*(LosMatrix4_4 mat1, LosMatrix4_4 mat2)
{
    LosMatrix4_4 backMatrix;

      // first row
    backMatrix.elements[0][0] = mat1.elements[0][0] * mat2.elements[0][0] + mat1.elements[1][0] * mat2.elements[0][1]+ mat1.elements[2][0] * mat2.elements[0][2] + mat1.elements[3][0] * mat2.elements[0][3];

     backMatrix.elements[1][0] = mat1.elements[0][0] * mat2.elements[1][0] + mat1.elements[1][0] * mat2.elements[1][1]+ mat1.elements[2][0] * mat2.elements[1][2] + mat1.elements[3][0] * mat2.elements[1][3];

     backMatrix.elements[2][0] = mat1.elements[0][0] * mat2.elements[2][0] + mat1.elements[1][0] * mat2.elements[2][1]+ mat1.elements[2][0] * mat2.elements[2][2] + mat1.elements[3][0] * mat2.elements[2][3];

     backMatrix.elements[3][0] = mat1.elements[0][0] * mat2.elements[3][0] + mat1.elements[1][0] * mat2.elements[3][1]+ mat1.elements[2][0] * mat2.elements[3][2] + mat1.elements[3][0] * mat2.elements[3][3];

      // second's row
    backMatrix.elements[0][1] = mat1.elements[0][1] * mat2.elements[0][0] + mat1.elements[1][1] * mat2.elements[0][1]+ mat1.elements[2][1] * mat2.elements[0][2] + mat1.elements[3][1] * mat2.elements[0][3];

    backMatrix.elements[1][1] = mat1.elements[0][1] * mat2.elements[1][0] + mat1.elements[1][1] * mat2.elements[1][1]+ mat1.elements[2][1] * mat2.elements[1][2] + mat1.elements[3][1] * mat2.elements[1][3];

    backMatrix.elements[2][1] = mat1.elements[0][1] * mat2.elements[2][0] + mat1.elements[1][1] * mat2.elements[2][1]+ mat1.elements[2][1] * mat2.elements[2][2] + mat1.elements[3][1] * mat2.elements[2][3];

    backMatrix.elements[3][1] = mat1.elements[0][1] * mat2.elements[3][0] + mat1.elements[1][1] * mat2.elements[3][1]+ mat1.elements[2][1] * mat2.elements[3][2] + mat1.elements[3][1] * mat2.elements[3][3];


    // third's row
    backMatrix.elements[0][2] = mat1.elements[0][2] * mat2.elements[0][0] + mat1.elements[1][2] * mat2.elements[0][1]+ mat1.elements[2][2] * mat2.elements[0][2] + mat1.elements[3][2] * mat2.elements[0][3];

    backMatrix.elements[1][2] = mat1.elements[0][2] * mat2.elements[1][0] + mat1.elements[1][2] * mat2.elements[1][1]+ mat1.elements[2][2] * mat2.elements[1][2] + mat1.elements[3][2] * mat2.elements[1][3];

    backMatrix.elements[2][2] = mat1.elements[0][2] * mat2.elements[2][0] + mat1.elements[1][2] * mat2.elements[2][1]+ mat1.elements[2][2] * mat2.elements[2][2] + mat1.elements[3][2] * mat2.elements[2][3];

    backMatrix.elements[3][2] = mat1.elements[0][2] * mat2.elements[3][0] + mat1.elements[1][2] * mat2.elements[3][1]+ mat1.elements[2][2] * mat2.elements[3][2] + mat1.elements[3][2] * mat2.elements[3][3];



    // four's row
    backMatrix.elements[0][3] = mat1.elements[0][3] * mat2.elements[0][0] + mat1.elements[1][3] * mat2.elements[0][1]+ mat1.elements[2][3] * mat2.elements[0][2] + mat1.elements[3][3] * mat2.elements[0][3];

    backMatrix.elements[1][3] = mat1.elements[0][3] * mat2.elements[1][0] + mat1.elements[1][3] * mat2.elements[1][1]+ mat1.elements[2][3] * mat2.elements[1][2] + mat1.elements[3][3] * mat2.elements[1][3];

    backMatrix.elements[2][3] = mat1.elements[0][3] * mat2.elements[2][0] + mat1.elements[1][3] * mat2.elements[2][1]+ mat1.elements[2][3] * mat2.elements[2][2] + mat1.elements[3][3] * mat2.elements[2][3];

    backMatrix.elements[3][3] = mat1.elements[0][3] * mat2.elements[3][0] + mat1.elements[1][3] * mat2.elements[3][1]+ mat1.elements[2][3] * mat2.elements[3][2] + mat1.elements[3][3] * mat2.elements[3][3];


    return backMatrix;
}


LosMatrix4_4 backMatrixLosQuater(LosQuaternion& quater)
{
    LosMatrix4_4 serBack = identity();
    
//    float sx = quater.x * quater.x,
//    sy = quater.y * quater.y,
//    sz = quater.z * quater.z,
//  //  sw = quater.w * quater.w,
//    inv = 1.0f / (sx + sy + sz + sw);
//
//    serBack.elements[0][0] = (sx - sy - sz + sw) * inv;
//    serBack.elements[1][1] = ( -sx + sy - sz + sw) * inv;
//    serBack.elements[2][2] = ( -sx - sy + sz + sw) * inv;
//    inv *= 2.0f;
//
//    float t1 = quater.x * quater.y;
//   // float t2 = quater.z * quater.w;
//
//    serBack.elements[1][0] = (t1 + t2) * inv;
//    serBack.elements[0][1] = (t1 - t2) * inv;
//
//    t1 = quater.x * quater.z;
//   // t2 = quater.y * quater.w;
//
//    serBack.elements[2][0] = (t1 - t2) * inv;
//    serBack.elements[0][2] = (t1 + t2) * inv;
//
//    t1 = quater.y * quater.z;
//    t2 = quater.x * quater.w;
//    serBack.elements[2][1] = (t1 + t2) * inv;
//    serBack.elements[1][2] = (t1 - t2) * inv;
    
    return serBack;
}


LosVector2  operator*(LosVector2 v1, LosVector2 v2)
{
    
    return LosVector2(v1.x * v2.x, v1.y * v2.y);
}

LosVector2  operator/(LosVector2 v1, LosVector2 v2)
{
    
    return LosVector2(v1.x/v2.x, v1.y/v2.y);
}

LosVector2  operator/(LosVector2 v1, float v2)
{
    return LosVector2(v1.x/v2, v1.y/ v2);
}

LosVector2  operator+(LosVector2 v1, LosVector2 v2)
{
    return LosVector2(v1.x + v2.x, v1.y + v2.y);
}

LosVector2  operator-(LosVector2 v1, LosVector2 v2)
{
    return LosVector2(v1.x - v2.x, v1.y - v2.y);
}
LosVector3 operator*(LosVector3 vec, float sca)
{
    
    return LosVector3(vec.x * sca, vec.y * sca, vec.z * sca);
}

LosVector3 operator*(LosVector3 vec, LosVector3 vec2)
{
    // vec.x   vec.y    vec.z
   // vec2.x  vec2.y   vec2.z
  
    
    float x1 = vec.y * vec2.z - vec.z * vec2.y;
    float x2 = vec.x * vec2.z - vec.z * vec2.x;
    float x3 = vec.x * vec2.y - vec.y * vec2.x;
    
    return LosVector3(x1, x2, x3);
}




LosVector3 operator+(LosVector3 vec, LosVector3 vec2)
{
    
    return LosVector3(vec.x + vec2.x, vec.y + vec2.y, vec.z + vec2.z);
}

LosQuaternion operator*(LosQuaternion qu1, LosQuaternion qu2)
{
    LosVector3 b1(qu1.x, qu1.y, qu1.z);
    LosVector3 b2(qu2.x, qu2.y, qu2.z);
    
    float aElement = (qu1.x * qu2.x) - b1.dot(b2);
    
    LosVector3 ass = b2 * qu1.x;
    
    LosVector3 wee = b1 * qu2.x;  // a qu2.x * b1 - not work&&& !
    

    return LosQuaternion(aElement, ass + wee + b1.cross(b2));

}


LosVector4 operator*(LosVector4 lvec, LosMatrix4_4 mat)
{
    LosVector4 retVec;
    
    retVec.x = mat.elements[0][0] * lvec.x + mat.elements[1][0] * lvec.y + mat.elements[2][0] * lvec.z + mat.elements[3][0] * lvec.w;
    
     retVec.y = mat.elements[0][1] * lvec.x + mat.elements[1][1] * lvec.y + mat.elements[2][1] * lvec.z + mat.elements[3][1] * lvec.w;
    
     retVec.z = mat.elements[0][2] * lvec.x + mat.elements[1][2] * lvec.y + mat.elements[2][2] * lvec.z + mat.elements[3][2] * lvec.w;
    
     retVec.w = mat.elements[0][3] * lvec.x + mat.elements[1][3] * lvec.y + mat.elements[2][3] * lvec.z + mat.elements[3][3] * lvec.w;
    
    return retVec;
}

LosVector4 operator*(LosMatrix4_4 mat, LosVector4 lvec)
{
    LosVector4 returnVec;
    
    returnVec.x = lvec.x * mat.elements[0][0] + lvec.y * mat.elements[0][1] + lvec.z * mat.elements[0][2] + lvec.w * mat.elements[0][3];
    
    returnVec.y = lvec.x * mat.elements[1][0] + lvec.y * mat.elements[1][1] + lvec.z * mat.elements[1][2] + lvec.w * mat.elements[1][3];
    
    returnVec.z = lvec.x * mat.elements[2][0] + lvec.y * mat.elements[2][1] + lvec.z * mat.elements[2][2] + lvec.w * mat.elements[2][3];
    
    returnVec.w = lvec.x * mat.elements[3][0] + lvec.y * mat.elements[3][1] + lvec.z * mat.elements[3][2] + lvec.w * mat.elements[3][3];
    
    return returnVec;
}


LosVector3 cross(LosVector3& v1, LosVector3& v2)
{
    LosVector3 backV;
    
    backV.x = (v1.y * v2.z - v2.y * v1.z);
    backV.y = (v1.x * v2.z - v2.x * v1.z);
    backV.z = (v1.x * v2.y - v2.x * v1.y);
    
    return backV;
    
}


LosMatrix4_4 operator*(LosMatrix4_4 mat, float s_var)
{
    for(int i = 0; i < 4; i++ )
    {
        for (int j = 0; j < 4; j++)
          mat.elements[i][j] = mat.elements[i][j] * s_var;
    }
    
    return mat;
}




LosMatrix4_4 inverse(LosMatrix4_4 mat)
{
    
    float a0 = mat.elements[0][0] * mat.elements[1][1] - mat.elements[0][1] * mat.elements[1][0];
    float a1 = mat.elements[0][0] * mat.elements[1][2] - mat.elements[0][2] * mat.elements[1][0];
    float a2 = mat.elements[0][0] * mat.elements[1][3] - mat.elements[0][3] * mat.elements[1][0];
    float a3 = mat.elements[0][1] * mat.elements[1][2] - mat.elements[0][2] * mat.elements[1][1];
    float a4 = mat.elements[0][1] * mat.elements[1][3] - mat.elements[0][3] * mat.elements[1][1];
    float a5 = mat.elements[0][2] * mat.elements[1][3] - mat.elements[0][3] * mat.elements[1][2];
    
    float b0 = mat.elements[2][0] * mat.elements[3][1] - mat.elements[2][1] * mat.elements[3][0];
    float b1 = mat.elements[2][0] * mat.elements[3][2] - mat.elements[2][2] * mat.elements[3][0];
    float b2 = mat.elements[2][0] * mat.elements[3][3] - mat.elements[2][3] * mat.elements[3][0];
    float b3 = mat.elements[2][1] * mat.elements[3][2] - mat.elements[2][2] * mat.elements[3][1];
    float b4 = mat.elements[2][1] * mat.elements[3][3] - mat.elements[2][3] * mat.elements[3][1];
    float b5 = mat.elements[2][2] * mat.elements[3][3] - mat.elements[2][3] * mat.elements[3][2];
    
    float det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
    float inv_det = 1.0f / det;
    
    
    LosMatrix4_4 inv = identity();
    inv.elements[0][0] = + mat.elements[1][1] * b5 - mat.elements[1][2] * b4 + mat.elements[1][3] * b3;
    inv.elements[1][0] = - mat.elements[1][0] * b5 + mat.elements[1][2] * b2 - mat.elements[1][3] * b1;
    inv.elements[2][0] = + mat.elements[1][0] * b4 - mat.elements[1][1] * b2 + mat.elements[1][3] * b0;
    inv.elements[3][0] = - mat.elements[1][0] * b3 + mat.elements[1][1] * b1 - mat.elements[1][2] * b0;
    inv.elements[0][1] = - mat.elements[0][1] * b5 + mat.elements[0][2] * b4 - mat.elements[0][3] * b3;
    inv.elements[1][1] = + mat.elements[0][0] * b5 - mat.elements[0][2] * b2 + mat.elements[0][3] * b1;
    inv.elements[2][1] = - mat.elements[0][0] * b4 + mat.elements[0][1] * b2 - mat.elements[0][3] * b0;
    inv.elements[3][1] = + mat.elements[0][0] * b3 - mat.elements[0][1] * b1 + mat.elements[0][2] * b0;
    inv.elements[0][2] = + mat.elements[3][1] * a5 - mat.elements[3][2] * a4 + mat.elements[3][3] * a3;
    inv.elements[1][2] = - mat.elements[3][0] * a5 + mat.elements[3][2] * a2 - mat.elements[3][3] * a1;
    inv.elements[2][2] = + mat.elements[3][0] * a4 - mat.elements[3][1] * a2 + mat.elements[3][3] * a0;
    inv.elements[3][2] = - mat.elements[3][0] * a3 + mat.elements[3][1] * a1 - mat.elements[3][2] * a0;
    inv.elements[0][3] = - mat.elements[2][1] * a5 + mat.elements[2][2] * a4 - mat.elements[2][3] * a3;
    inv.elements[1][3] = + mat.elements[2][0] * a5 - mat.elements[2][2] * a2 + mat.elements[2][3] * a1;
    inv.elements[2][3] = - mat.elements[2][0] * a4 + mat.elements[2][1] * a2 - mat.elements[2][3] * a0;
    inv.elements[3][3] = + mat.elements[2][0] * a3 - mat.elements[2][1] * a1 + mat.elements[2][2] * a0;
    
    

    inv = inv * inv_det;
    
    return inv;
}

LosVector3 unProject(LosVector3 one3, LosMatrix4_4 view, LosMatrix4_4 proj, LosVector4& ve4)
{
    
    
    LosMatrix4_4 inv = inverse(proj * view);
    
    LosVector4 tmp = *new LosVector4(one3, 1.0f);
    
    tmp.x = (tmp.x - ve4.x)/ve4.z;
    tmp.y = (tmp.y - ve4.y)/ve4.w;
    
    tmp = tmp * 2 - 1;
    
    LosVector4 ovkml = inv * tmp;
    
    return LosVector3(ovkml.x/ovkml.w, ovkml.y/ovkml.w, ovkml.z/ovkml.w);
}

LosVector4 operator*(LosVector4 ve, float s_float)
{
    ve.x = ve.x * s_float;
    ve.y = ve.y * s_float;
    ve.z = ve.z * s_float;
    ve.w = ve.w * s_float;
    
    return ve;
    
}

LosVector4 operator-(LosVector4 ve, float s_float)
{
    ve.x = ve.x - s_float;
    ve.y = ve.y - s_float;
    ve.z = ve.z - s_float;
    ve.w = ve.w - s_float;
    
    return ve;
}


//LosVector3 operator-(LosVector3 vec1, LosVector3 vec2)
//{
//    
//    LosVector3 serV{ vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z };
//    
//    return serV;
//}


LosVector3 minVec3(LosVector3& vec, LosVector3& vec2)
{
    float a, b, c;

    
    a = (/* DISABLES CODE */ (vec.x) < vec2.x) ? vec.x : vec2.x;
        b = (/* DISABLES CODE */ (vec.y) < vec2.y) ? vec.y : vec2.y;
        c = (/* DISABLES CODE */ (vec.z) < vec2.z) ? vec.z : vec2.z;
    
   // printf(" gg88  == %f %f and %f \n", a, b, c);
    
    return LosVector3(a,b,c);
}


LosVector3 maxVec3(LosVector3& vec, LosVector3& vec2)
{
    float a, b, c;
    
    
    a = (/* DISABLES CODE */ (vec.x) > vec2.x) ? vec.x : vec2.x;
    b = (/* DISABLES CODE */ (vec.y) > vec2.y) ? vec.y : vec2.y;
    c = (/* DISABLES CODE */ (vec.z) > vec2.z) ? vec.z : vec2.z;
    
   // printf(" gg88 max == %f %f and %f \n", a, b, c);
    
    return LosVector3(a,b,c);
}


LosVector4 vector_four_matr_four(LosVector4& lQ, LosMatrix4_4& mat)
{
    LosVector4 backVector;// = LosVector4::LosVector4();


    backVector.x = (mat.elements[0][0] * lQ.x) + (mat.elements[1][0] * lQ.y) + (mat.elements[2][0] * lQ.z) +(mat.elements[3][0] * lQ.w);


    backVector.y = mat.elements[0][1] * lQ.x + mat.elements[1][1] * lQ.y + mat.elements[2][1] * lQ.z +mat.elements[3][1] * lQ.w;

    backVector.z = mat.elements[0][2] * lQ.x + mat.elements[1][2] * lQ.y + mat.elements[2][2] * lQ.z +mat.elements[3][2] * lQ.w;


    backVector.w = mat.elements[0][3] * lQ.x + mat.elements[1][3] * lQ.y + mat.elements[2][3] * lQ.z +mat.elements[3][3] * lQ.w;



    return backVector;
}

LosVector3 operator*(LosMatrix3_3& lMat, LosVector3& lVec)
{
    LosVector3 backVect;
    backVect.x = lMat.elements[0][0] * lVec.x + lMat.elements[1][0] * lVec.y + lMat.elements[2][0] * lVec.z;
    backVect.y = lMat.elements[0][1] * lVec.x + lMat.elements[1][1] * lVec.y + lMat.elements[2][1] * lVec.z;
    backVect.z = lMat.elements[0][2] * lVec.x + lMat.elements[1][2] * lVec.y + lMat.elements[2][2] * lVec.z;
    
    return backVect;
}

LosVector3 operator*(LosVector3& lVec, LosMatrix3_3& lMat)
{
    LosVector3 backVect;
    backVect.x = lMat.elements[0][0] * lVec.x + lMat.elements[0][1] * lVec.y + lMat.elements[0][2] * lVec.z;
    backVect.y = lMat.elements[1][0] * lVec.x + lMat.elements[1][1] * lVec.y + lMat.elements[1][2] * lVec.z;
    backVect.z = lMat.elements[2][0] * lVec.x + lMat.elements[2][1] * lVec.y + lMat.elements[2][2] * lVec.z;
    
    return backVect;
}


/**
 *  Tranpose matrix
 */


LosMatrix4_4 transpo(LosMatrix4_4& mat)
{

    float temp  = mat.elements[0][1];
    mat.elements[0][1] = mat.elements[1][0];
    mat.elements[1][0] = temp;

    temp  = mat.elements[0][2];
    mat.elements[0][2] = mat.elements[2][0];
    mat.elements[2][0] = temp;

    temp  = mat.elements[0][3];
    mat.elements[0][3] = mat.elements[3][0];
    mat.elements[3][0] = temp;

    temp  = mat.elements[1][2];
    mat.elements[1][2] = mat.elements[2][1];
    mat.elements[2][1] = temp;

    temp  = mat.elements[1][3];
    mat.elements[1][3] = mat.elements[3][1];
    mat.elements[3][1] = temp;

    temp  = mat.elements[2][3];
    mat.elements[2][3] = mat.elements[3][2];
    mat.elements[3][2] = temp;

    return mat;

}


 // -1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f
LosMatrix4_4 orthonormalMatrixRight(float left, float right, float bottom, float top, float zNear, float zFar)
{
    LosMatrix4_4 orthoMatrix;
    orthoMatrix = identity();

    /*[0][0]  [1][0]  [2][0]  [3][0]
      [0][1]  [1][1]  [2][1]  [3][1]
      [0][2]  [1][2]  [2][2]  [3][2]
      [0][3]  [1][3]  [2][3]  [3][3]   */


    //    Result[0][0] = static_cast<T>(2) / (right - left);
    //    Result[1][1] = static_cast<T>(2) / (top - bottom);
    //    Result[2][2] = - static_cast<T>(2) / (zFar - zNear);
    //    Result[3][0] = - (right + left) / (right - left);
    //    Result[3][1] = - (top + bottom) / (top - bottom);
    //    Result[3][2] = - (zFar + zNear) / (zFar - zNear);
    orthoMatrix.elements[0][0] = 2 / (right - left);
    orthoMatrix.elements[1][1] = 2 / (top - bottom);
    orthoMatrix.elements[2][2] = -2 / (zFar - zNear);
    orthoMatrix.elements[3][0] = -(right + left) / (right - bottom);
    orthoMatrix.elements[3][1] = - (top + bottom) / (top - bottom);
    orthoMatrix.elements[3][2] = - (zFar + zNear) / (zFar - zNear);

    return orthoMatrix;
}




