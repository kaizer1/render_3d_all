//
//  LosVector4.cpp
//  C_Plus_Plus_Engine
//
//  Created by Сергей Лоскутников on 03/12/2016.
//  Copyright © 2016 sergey.loscutnikov.phoridaeentertainment. All rights reserved.
//

#include "LosVector4.hpp"

LosVector4::LosVector4()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 0.0f;
}
LosVector4::LosVector4( const LosVector4& def)
{
    x = def.x;
    y = def.y;
    z = def.z;
    w = def.w;
}


LosVector4::~LosVector4()
{
    x = 0;
    y = 0;
    z = 0;
    w = 0;
}

LosVector4::LosVector4(LosVector3 vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
    w = 1.0f;
}


LosVector4::LosVector4(LosVector3 vec, float w1)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
    w = w1;
}

//LosVector4::LosVector4(LosVector3& vec, float w1)
//{
//    x = vec.x;
//    y = vec.y;
//    z = vec.z;
//    w = w1;
//}

LosVector4::LosVector4(float x1,float y1, float z1, float w1)
{
    x = x1;
    y = y1;
    z = z1;
    w = w1;
}


LosVector4::LosVector4(float x1, float y1, float z1)
{
    x = x1;
    y = y1;
    z = z1;
    w = 1.0f;
}


LosVector4::LosVector4(float x, float y)
{
    
}

LosVector4::LosVector4(const float vec)
{
    x = vec;
    y = vec;
    z = vec;
    w = vec;
}


LosVector4 LosVector4::operator-(LosVector4& vec)
{
    x = x - vec.x;
    y = y - vec.y;
    z = z - vec.z;
    w = w - vec.w;
    
    return *this;
}




