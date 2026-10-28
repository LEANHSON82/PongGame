#include <raylib.h>
#include "gameMain.h"
#include "screens/gameplayScreen.h"
bool initGame()
{
    initGameplay();
    return true;
}

bool updateGame()
{
    updateGameplay();
    drawGameplay();
    return true;
}

void closeGame()
{
}