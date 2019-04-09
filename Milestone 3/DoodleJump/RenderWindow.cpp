//
//  RenderWindow.cpp
//  DoodleJump
//
//  Created by Aichinger,Julie.
//  Copyright © 2019 Aichinger,Julie. All rights reserved.
//

#include "RenderWindow.hpp"
#include <time.h>

void CreateWindow::MakeWindow()
{
    srand(time(0));

    RenderDetails getDetails;
    getDetails.CreateDetails();
}
