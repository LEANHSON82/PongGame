#include <raylib.h>
#include "gameConfig.h"
#include "entities/paddle.h"

void Paddle::limitMovement()
{
    if (pos_y <= 0)
    {
        pos_y = 0;
    }

    if (pos_y + height >= GetScreenHeight())
    {
        pos_y = GetScreenHeight() - height;
    }
}

void Paddle::draw()
{
    DrawRectangleRounded(Rectangle{pos_x, pos_y, width, height}, 0.8, 0, WHITE);
}

void Paddle::update()
{
    if (IsKeyDown(KEY_W))
    {
        pos_y -= speed;
    }

    if (IsKeyDown(KEY_S))
    {
        pos_y += speed;
    }

    limitMovement();
}

void cpuPaddle::update(int ball_pos_y)
{
    if (pos_y + height / 2 < ball_pos_y)
    {
        pos_y += speed;
    }

    if (pos_y + height / 2 >= ball_pos_y)
    {
        pos_y -= speed;
    }

    limitMovement();
}