//
//  LosVector3.cpp
//  C_Plus_Plus_Engine
//
//  Created by Сергей Лоскутников on 31/10/2016.
//  Copyright © 2016 sergey.loscutnikov.phoridaeentertainment. All rights reserved.
//

#include "LosVector3.hpp"

#include <math.h>



LosVector3::LosVector3()
{
    x = 1.0f;
    y = 1.0f;
    z = 1.0f;
    
}

LosVector3::LosVector3(float& vec)
{
    x = vec;
    y = 1.0f;
    z = 1.0f;
}

//LosVector3::LosVector3(LosVector3&& lVector)
//{
//    x = std::move(lVector.x);
//    y = std::move(lVector.y);
//    z = std::move(lVector.z);
//
//}

LosVector3::LosVector3(const LosVector3& lVerr)
{
    x = lVerr.x;
    y = lVerr.y;
    z = lVerr.z;
}

LosVector3::LosVector3(LosVector3& lVerr)
{
    x = lVerr.x;
    y = lVerr.y;
    z = lVerr.z;
}

//LosVector3::LosVector3(float& vec1, float& vec2, float& v3)
//{
//    x = vec1;
//    y = vec2;
//    z = v3;
//}

LosVector3::LosVector3(float x1, float y1, float z1)
{
    x = x1;
    y = y1;
    z = z1;
}

LosVector3::LosVector3(LosVector2 v2, float z1)
{
    x = v2.x;
    y = v2.y;
    z = z1;
}

LosVector3 LosVector3::normalized()
{
    
    LosVector3 vectorBack;
    
    float squart = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    
    if(squart == 0)
    {
        return vectorBack;
    }
    else
    {
        x = x/squart;
        y = y/squart;
        z = z/squart;
        
        return *this;
    }
    
}

LosVector3 LosVector3::operator-(LosVector3& vec)
{
    float xN, yN, zN;
    xN = x - vec.x;
    yN = y - vec.y;
    zN = z - vec.z;
    LosVector3 a (xN, yN, zN);
    
    return a;
}



LosVector3 LosVector3::cross(LosVector3& vec3)
{
    float a, b , c;
    a = (y * vec3.z - vec3.y * z);
    b = (x * vec3.z - vec3.x * z) * (-1);
    c = (x * vec3.y - vec3.x * y);
    x = a;
    y = b;
    z = c;
    return *this;
}



float LosVector3::dot(LosVector3& vec3)
{
    float resultNumber;
    resultNumber = x * vec3.x + y * vec3.y + z * vec3.z;
    return resultNumber;
}


LosVector3::~LosVector3()
{
    x = 0;
    y = 0;
    z = 0;
}

void LosVector3::losSeeElement(LosVector3& vect)
{
    
    printf(" my vector variable x == %f \n", vect.x);
    printf(" my vector variable y == %f \n", vect.y);
    printf(" my vector variable z == %f \n", vect.z);
    
    
}

void LosVector3::losSeeElement()
{
    printf(" my vector variable x == %f \n", x);
    printf(" my vector variable y == %f \n", y);
    printf(" my vector variable z == %f \n", z);
}


LosVector3 LosVector3::operator+=(LosVector3& vec)
{
    x = x + vec.x;
    y = y + vec.y;
    z = z + vec.z;

    return *this;
}

