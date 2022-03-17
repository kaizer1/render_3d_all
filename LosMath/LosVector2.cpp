//
//  LosVector2.cpp
//  C_Plus_Plus_Engine
//
//  Created by Сергей Лоскутников on 22/12/2016.
//  Copyright © 2016 sergey.loscutnikov.phoridaeentertainment. All rights reserved.
//

#include "LosVector2.hpp"



LosVector2::LosVector2()
{
    x = 1.0f;
    y = 1.0f;
}

LosVector2::~LosVector2()
{
    x = 0;
    y = 0;
}


void LosVector2::getValue(const float& a,const float& b)
{
    x = a;
    y = b;
}


LosVector2::LosVector2(float a)
{
    x = a;
    y = 0.0f;
}


LosVector2::LosVector2(float a, float b)
{
    x = a;
    y = b;
}



LosVector2 LosVector2::operator*(LosVector2 v)
{
    
    x = x * v.x;
    y = y * v.y;
    return *this;
}

float LosVector2::dot(LosVector2& vec)
{
    float ssd;
    ssd = x * vec.x + y * vec.y;
    
    return ssd;
}


LosVector2 LosVector2::operator*(float sca)
{
    x = x * sca;
    y = y * sca;
    
    return *this;
}

LosVector2 LosVector2::operator+=(LosVector2 v)
{
    x = x + v.x;
    y = y + v.y;
    return *this;
}



