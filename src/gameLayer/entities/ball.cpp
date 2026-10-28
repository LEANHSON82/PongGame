#include <raylib.h>
#include "entities/ball.h"
#include "gameConfig.h"

void Ball::draw()
{
    DrawCircle(pos_x, pos_y, radius, summer);
}

void Ball::update()
{
    if (pos_x + radius >= GetScreenWidth() || pos_x - radius <= 0)
    {
        speed_x *= -1;
    }

    if (pos_y + radius >= GetScreenHeight() || pos_y - radius <= 0)
    {
        speed_y *= -1;
    }

    pos_x += speed_x;
    pos_y += speed_y;
}

void Ball::reset()
{
    pos_x = GetScreenWidth() / 2;
    pos_y = GetScreenHeight() / 2;

    int speedChoices[2] = {-1, 1};
    speed_x *= speedChoices[GetRandomValue(0, 1)];
    speed_y *= speedChoices[GetRandomValue(0, 1)];
}