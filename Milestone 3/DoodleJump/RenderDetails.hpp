//
//  RenderDetails.hpp
//  DoodleJump
//
//  Created by Aichinger,Julie.
//  Copyright © 2019 Aichinger,Julie. All rights reserved.
//

#ifndef RenderDetails_hpp
#define RenderDetails_hpp

#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

class RenderDetails
{
    int x = 100, y = 100, h = 200;
    float dx = 0, dy = 0;

public:
    void CreateDetails();
};


#endif /* RenderDetails_hpp */
