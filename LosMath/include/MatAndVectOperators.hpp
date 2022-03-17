//
//  MatAndVectOperators.hpp
//  C_Plus_Plus_Engine
//
//  Created by Сергей Лоскутников on 01/11/2016.
//  Copyright © 2016 sergey.loscutnikov.phoridaeentertainment. All rights reserved.
//

#pragma once

#include <stdio.h>

#include "LosVector2.hpp"
#include "LosVector3.hpp"
#include "LosVector4.hpp"
#include "LosMatrix4_4.hpp"
#include "LosQuaternion.hpp"

#include "LosMatrix3_3.hpp"


//#include <SIMD/SIMD.h>

LosMatrix4_4 perspectiveLosRithg(float FOV, float aspect, float near, float far);

LosMatrix4_4 LookAt_RightLos(LosVector3 eye, LosVector3 center, LosVector3 up, LosMatrix4_4& mat);

LosMatrix4_4 identity();

void losSeeMatrixElements(LosMatrix4_4 mat);

LosMatrix4_4 operator*(LosMatrix4_4 mat1, LosMatrix4_4 mat2);

LosVector2  operator/(LosVector2 v1, LosVector2 v2);

LosVector2  operator/(LosVector2 v1, float v2);


LosVector2  operator+(LosVector2 v1, LosVector2 v2);

LosVector2  operator-(LosVector2 v1, LosVector2 v2);

LosVector3 operator*(LosVector3 vec, float sca);

LosVector3 operator*(LosVector3 vec, LosVector3 vec2);

LosVector3 operator+(LosVector3 vec, LosVector3 vec2);
LosVector3 minVec3(LosVector3& vec, LosVector3& vec2);
LosVector3 maxVec3(LosVector3& vec, LosVector3& vec2);


LosQuaternion operator*(LosQuaternion qu1, LosQuaternion qu2);

            /*
                 ******
                ******    operations Matrix !
                 ******
             
             */

LosMatrix4_4 backMatrixLosQuater(LosQuaternion& quater);

LosVector4 operator*(LosMatrix4_4 mat, LosVector4 lvec);
LosVector4 operator*(LosVector4 lvec, LosMatrix4_4 mat);

LosVector3 cross(LosVector3& v1, LosVector3& v2);

LosMatrix4_4 inverse(LosMatrix4_4 mat);
LosMatrix4_4 transpo(LosMatrix4_4& mat);

LosMatrix4_4 operator*(LosMatrix4_4 mat, float s_var);
LosVector4 operator*(LosVector4 ve, float s_float);
LosVector4 operator-(LosVector4 ve, float s_float);

LosVector3 unProject(LosVector3 one3, LosMatrix4_4 view, LosMatrix4_4 proj, LosVector4& ve4);

LosVector4 vector_four_matr_four(LosVector4& lQ, LosMatrix4_4& matrix);
LosVector3 operator*(LosMatrix3_3& lMat, LosVector3& lVec);
LosVector3 operator*(LosVector3& lVec, LosMatrix3_3& lMat);
LosMatrix4_4 orthonormalMatrixRight(float left, float right, float bottom, float top, float zNear, float zFar);

/* MatAndVectOperators_hpp */
