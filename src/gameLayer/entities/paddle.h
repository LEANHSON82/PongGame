#pragma once

class Paddle
{
protected:
    void limitMovement();

public:
    float width, height;
    float pos_x, pos_y;
    int speed;

    void draw();
    void update();
};

class cpuPaddle : public Paddle
{
public:
    void update(int ball_pos_y);
};