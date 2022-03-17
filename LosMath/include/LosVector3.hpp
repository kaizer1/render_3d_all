//
//  LosVector3.hpp
//  C_Plus_Plus_Engine
//
//  Created by Сергей Лоскутников on 31/10/2016.
//  Copyright © 2016 sergey.loscutnikov.phoridaeentertainment. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "LosVector2.hpp"

class LosVector3
{
    
public:
    
    LosVector3();
    ~LosVector3();
    
    LosVector3(float& vec);
   // LosVector3(LosVector3&& lVector);  // move constructor
    LosVector3(LosVector3& lVerr);

     LosVector3(const LosVector3& lVerr);

   // LosVector3(float& vec1, float& vec2, float& v3);
    
    LosVector3(float x, float y, float z);
    LosVector3(LosVector2 v2, float z);
    
    LosVector3 operator-(LosVector3& vec);
    LosVector3 operator+=(LosVector3& vec);
    
   // void operator* (float scale);
    
   // LosVector3 operator=(const LosVector3& vec) const;
    
    LosVector3 normalized();
    LosVector3 cross(LosVector3& vec);
    float dot(LosVector3& vec);
    
    void losSeeElement(LosVector3& vect);
    void losSeeElement();


    bool operator==(LosVector3& ver)
    {
        if(x != ver.x)
            return false;

        if(y != ver.y)
            return false;

        if(z != ver.z)
            return false;

        return true;
    }
    
    float x;
    float y;
    float z;
    
private:
    
    
    
};






 /* LosVector3_hpp */
