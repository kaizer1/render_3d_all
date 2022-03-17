//
//  LosVector4.hpp
//  C_Plus_Plus_Engine
//
//  Created by Сергей Лоскутников on 03/12/2016.
//  Copyright © 2016 sergey.loscutnikov.phoridaeentertainment. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "LosVector3.hpp"
//#include "LosMatrix4_4.hpp"




class LosVector4
{
public:
    
    LosVector4();
    ~LosVector4();

    LosVector4(const LosVector4& def);
   
    LosVector4(LosVector3 vec3);
   // LosVector4(LosVector3& vec3, float w);
    LosVector4(LosVector3 vec, float w1);
    LosVector4(float x, float y, float z, float w);
    LosVector4(float x, float y, float z);
    LosVector4(float x, float y);
    LosVector4(const float vec);
    
    LosVector4 operator-(LosVector4& vec);
    
    float x;
    float y;
    float z;
    float w;
    
};

/* LosVector4_hpp */
