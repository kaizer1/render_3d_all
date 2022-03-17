//
//  LosQuaternion.cpp
//  C_Plus_Plus_Engine
//
//  Created by Сергей Лоскутников on 31/10/2016.
//  Copyright © 2016 sergey.loscutnikov.phoridaeentertainment. All rights reserved.
//

#include "LosQuaternion.hpp"

LosQuaternion::LosQuaternion()
{
    s = 1.0f;

    x = 1.0f;
    y = 1.0f;
    z = 1.0f;

}


LosQuaternion::~LosQuaternion()
{
    s = 0.0f;

    x = 0.0f;
    y = 0.0f;
    z = 0.0f;

}

LosQuaternion::LosQuaternion(float x_sca, LosVector3 vec3)
{
    
    s = x_sca;

    x = vec3.x;
    y = vec3.y;
    z = vec3.z;
    
}


LosQuaternion::LosQuaternion(float e)
{
    s = e;
    x = 1.0f;
    y = 1.0f;
    z = 1.0f;
}

LosQuaternion::LosQuaternion(float e, float q)
{
    s = e;
    x = q;
    y = 1.0f;
    z = 1.0f;
}



LosQuaternion::LosQuaternion(float e, float q, float a)
{
    s = e;

    x = q;
    y = a;
    z = 1.0f;
}


LosQuaternion::LosQuaternion(float e, float q, float a, float b)
{
    s = e;
    x = q;
    y = a;
    z = b;
}




























