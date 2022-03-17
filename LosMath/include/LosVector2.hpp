//
//  LosVector2.hpp
//  C_Plus_Plus_Engine
//
//  Created by Сергей Лоскутников on 22/12/2016.
//  Copyright © 2016 sergey.loscutnikov.phoridaeentertainment. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <utility>

class LosVector2
{
    
public:
    
    
    LosVector2();
    ~LosVector2();
    
    
    
    LosVector2(float a);
    LosVector2(float a, float b);
    
    LosVector2 operator*(LosVector2 v);
    LosVector2 operator*(float sca);
    LosVector2 operator+=(LosVector2 v);
        
    float dot(LosVector2& vec);
    void getValue(const float& a, const float& b);
    
    float x;
    float y;



};



/* LosVector2_hpp */
