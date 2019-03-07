//
//  RenderDetails.cpp
//  DoodleJump
//
//  Created by Aichinger,Julie.
//  Copyright © 2019 Aichinger,Julie. All rights reserved.
//

#include "RenderDetails.hpp"

using namespace sf;

//Declare points
struct point
{
    int x, y;
};

void RenderDetails::CreateDetails(){
    
    RenderWindow app(VideoMode(400, 533), "Doodle Game!");
    app.setFramerateLimit(60);
    
    Texture t1,t2,t3;
    t1.loadFromFile(resourcePath() + "background.png");
    t2.loadFromFile(resourcePath() + "platform.png");
    t3.loadFromFile(resourcePath() + "doodle.png");
    
    Sprite sBackground(t1), sPlat(t2), sPers(t3);
    point plat[20];
    
    for (int i = 0; i < 10; i++) {
        plat[i].x = rand() % 400;
        plat[i].y = rand() % 533;
    }
    
    
    while (app.isOpen()) {
        Event e;
        while (app.pollEvent(e)) {
            if (e.type == Event::Closed)
                app.close();
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Right))
            x += 3;
        if (Keyboard::isKeyPressed(Keyboard::Left))
            x -= 3;
        
        dy += 0.2;
        y += dy;
        if (y > 500)
            dy = -10;
        
        if (y < h)
            for (int i = 0; i < 10; i++) {
                y = h;
                plat[i].y = plat[i].y - dy;
                if (plat[i].y > 533) {
                    plat[i].y = 0;
                    plat[i].x = rand() % 400;
                }
            }
        
        for (int i = 0; i < 10; i++)
            if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68) &&
                (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))
                dy = -10;
        
        sPers.setPosition(x, y);
        
        app.draw(sBackground);
        app.draw(sPers);
        for (int i = 0; i < 10; i++) {
            sPlat.setPosition(plat[i].x, plat[i].y);
            app.draw(sPlat);
        }
        
        app.display();
    }
    
}
