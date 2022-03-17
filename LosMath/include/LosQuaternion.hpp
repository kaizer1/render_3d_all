//
//  LosQuaternion.hpp
//  C_Plus_Plus_Engine
//
//  Created by Сергей Лоскутников on 31/10/2016.
//  Copyright © 2016 sergey.loscutnikov.phoridaeentertainment. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "LosVector3.hpp"


class LosQuaternion
{
public:
    
    LosQuaternion();
    ~LosQuaternion();
    
    
     LosQuaternion(float e);
     LosQuaternion(float e, float q);
     LosQuaternion(float e, float q, float a);
     LosQuaternion(float e, float q, float a, float b);
    
    LosQuaternion(float s, LosVector3 vec3);
 






    // Scalar
     float s;
    // Vector
     float x;
     float y;
     float z;

private:
    
};


/* LosQuaternion_hpp */
