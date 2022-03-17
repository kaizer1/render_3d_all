//
//  LosMatrix4_4.hpp
//  C_Plus_Plus_Engine
//
//  Created by Сергей Лоскутников on 31/10/2016.
//  Copyright © 2016 sergey.loscutnikov.phoridaeentertainment. All rights reserved.
//

#pragma once

//#pragma message "today we are ! "

#include <stdio.h>
#include "LosVector3.hpp"
#include "LosVector4.hpp"

#define _USE_MATH_DEFINES
#include <math.h>

inline static float halfPI = 180.0f;


template <typename T>
float degrees_to_radian(T deg)
{
    return static_cast<float>(deg * M_PI/halfPI);
}


class LosMatrix4_4
{
    
public:
    
    
    LosMatrix4_4();
    
    ~LosMatrix4_4();
    
    //LosMatrix4_4(float v = 1);
    LosMatrix4_4(LosVector3& vec1, LosVector3& vec2, LosVector3& vec3);
    LosMatrix4_4(LosVector3& vec1, LosVector3& vec2, LosVector3& vec3, LosVector3& vec4);
    
    LosMatrix4_4(LosVector4& vec1, LosVector4& vec2, LosVector4& vec3, LosVector4& vec4);

    //LosMatrix4_4 operator*(LosMatrix4_4 newMat);
    
    void ScaleLos(LosVector3 vecScale);
    void Transposition(LosVector3 vecTransposition);

    const LosMatrix4_4 iden() const
    {
        LosMatrix4_4 backMM;
        backMM.elements[0][0] = 1.0f;
        backMM.elements[0][1] = 0.0f;
        backMM.elements[0][2] = 0.0f;
        backMM.elements[0][3] = 0.0f;
        backMM.elements[1][0] = 0.0f;
        backMM.elements[1][1] = 1.0f;
        backMM.elements[1][2] = 0.0f;
        backMM.elements[1][3] = 0.0f;
        backMM.elements[2][0] = 0.0f;
        backMM.elements[2][1] = 0.0f;
        backMM.elements[2][2] = 1.0f;
        backMM.elements[2][3] = 0.0f;
        backMM.elements[3][0] = 0.0f;
        backMM.elements[3][1] = 0.0f;
        backMM.elements[3][2] = 0.0f;
        backMM.elements[3][3] = 1.0f;

        return backMM;
    }


    void rotateLosY(float angle);
    void rotateLosX(float angle);
    void rotateLosZ(float angle);
    void RotateWithOurAxilar(LosVector3 vec);
    
    float elements[4][4];



private:
    
    
};






 /* LosMatrix4_4_hpp */
