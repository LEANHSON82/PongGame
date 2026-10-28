#include <raylib.h>
#include "gameMain.h"
#include "gameConfig.h"

int main()
{

    InitWindow(screen_width, screen_height, "Pong game");
    SetTargetFPS(60);

    if (!initGame())
    {
        return 0;
    }

    while (!WindowShouldClose())
    {
        BeginDrawing();

        if (!updateGame())
        {
            break;
        }

        EndDrawing();
    }
    closeGame();
    CloseWindow();
    return 0;
}