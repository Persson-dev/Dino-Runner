#include "dino.h"

void InitialiseDino(dino &d)
{
    d.hitbox.h = 60;
    d.hitbox.w = 40;
    d.hitbox.x = 100;
    d.hitbox.y = 440;

    d.sens = "haut";
}

void jump(dino &d, int &x)
{
    if (d.sens.compare("haut") == 0)
    {
        if (x < 90)
        {
            d.hitbox.y -= 5;
        }
        else
        {
            if (d.hitbox.y + 5 < 450)
            {
                d.hitbox.y += 5;
            }
            else
            {
                x = 180;
            }
        }
    }
    else if (d.sens.compare("bas") == 0)
    {
        if (x < 90)
        {
            d.hitbox.y += 5;
        }
        else
        {
            if (d.hitbox.y - 5 > 540)
            {
                d.hitbox.y -= 5;
            }
            else
            {
                x = 180;
            }
        }
    }
}

void gravity(dino &d, bool space)
{
    if (d.sens.compare("haut") == 0)
    {
        if (d.hitbox.y < 450 && space == false)
        {
            d.hitbox.y = 440;
        }
    }
    else if (d.sens.compare("bas") == 0)
    {
        if (d.hitbox.y > 550 && space == false)
        {
            d.hitbox.y = 600;
        }
    }
}