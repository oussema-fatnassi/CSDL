#include <raylib.h>
#include "menu.hpp"
#include <iostream>
#include "grid.hpp"
#include "globals.hpp"
using namespace std;


void createButton(int x, int y, int width, int height, const char *text)
{
    DrawRectangle(x, y, width, height, WHITE);
    DrawText(text, x + 10, y + 15, 20, BLACK);
}

void spawnRandomButton()
{
    if (CheckCollisionPointRec(GetMousePosition(), {50, 620, 100, 50}))
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            cout << "Button clicked" << endl;
            randomSpawn(800, 600, 20);
        }
    }
}

void startSimulationButton()
{
    if (CheckCollisionPointRec(GetMousePosition(), {350, 620, 180, 50}))
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            cout << "Simulation started" << endl;
            isSimulationRunning = true;
        }
    }
}