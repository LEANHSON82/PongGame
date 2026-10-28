#pragma once

class Ball
{
public:
    int radius;
    int speed_x, speed_y;
    float pos_x, pos_y;

    void draw();
    void update();
    void reset();
};