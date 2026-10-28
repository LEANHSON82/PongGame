#include <raylib.h>
#include "screens/gameplayScreen.h"
#include <cstdlib>
#include "gameConfig.h"
#include "entities/ball.h"
#include "entities/paddle.h"
Ball ball;
Paddle player;
cpuPaddle cpu;

int player_score = 0;
int cpu_score = 0;

void initGameplay()
{
    // ball data
    ball.pos_x = screen_width / 2;
    ball.pos_y = screen_height / 2;
    ball.radius = 20;
    ball.speed_x = 7;
    ball.speed_y = 7;

    // player data
    player.width = 25;
    player.height = 120;
    player.pos_x = GetScreenWidth() - 10 - player.width;
    player.pos_y = (GetScreenHeight() - player.height) / 2;
    player.speed = 6;

    // cpu data
    cpu.width = 25;
    cpu.height = 120;
    cpu.pos_x = 10;
    cpu.pos_y = (GetScreenHeight() - cpu.height) / 2;
    cpu.speed = 6;
}

void updateGameplay()
{
    ball.update();
    player.update();
    cpu.update(ball.pos_y);

    // Scoring and reset ball
    if (ball.pos_x + ball.radius >= GetScreenWidth())
    {
        cpu_score += 1;
        ball.reset();
    }

    if (ball.pos_x - ball.radius <= 0)
    {
        player_score += 1;
        ball.reset();
    }

    // Checking for collisions
    if (CheckCollisionCircleRec(Vector2{ball.pos_x, ball.pos_y}, ball.radius, Rectangle{player.pos_x, player.pos_y, player.width, player.height}))
    {
        ball.speed_x = -abs(ball.speed_x);
    }

    if (CheckCollisionCircleRec(Vector2{ball.pos_x, ball.pos_y}, ball.radius, Rectangle{cpu.pos_x, cpu.pos_y, cpu.width, cpu.height}))
    {
        ball.speed_x = abs(ball.speed_x);
    }
}

void drawGameplay()
{
    ClearBackground(dark_blue);
    DrawRectangle(screen_width / 2, 0, screen_width / 2, screen_height, blue);
    DrawCircle(screen_width / 2, screen_height / 2, 150, light_blue);
    DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
    player.draw();
    cpu.draw();
    ball.draw();

    DrawText(TextFormat("%i", cpu_score), screen_width / 4 - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i", player_score), 3 * screen_width / 4, 20, 80, WHITE);
}