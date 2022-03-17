//
//  LosMatrix3_3.hpp
//  C_Plus_Plus_Engine
//
//  Created by Сергей Лоскутников on 31/10/2016.
//  Copyright © 2016 sergey.loscutnikov.phoridaeentertainment. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "LosVector3.hpp"
#include "LosQuaternion.hpp"



class LosMatrix3_3
{
public:
    
    LosMatrix3_3();
    ~LosMatrix3_3();
    
    LosMatrix3_3(LosVector3 x, LosVector3 y, LosVector3 z);
    
    void rotateLosX(float angle);
    void rotateLosY(float angle);
    void rotateLosZ(float angle);
    
    LosQuaternion getRotationMatrix(LosMatrix3_3& rotMat) const;
    
    
    float elements[3][3];
    
    LosMatrix3_3 ident();
    
    double degrees_to_radian(double deg);
    
    LosMatrix3_3 operator*(LosMatrix3_3& lMat);
    
    void retuIden();
    
};































/* LosMatrix3_3_hpp */
