#include <raylib.h>
#include "menu.hpp"
#include <iostream>
#include "grid.hpp"
#include "globals.hpp"
using namespace std;

bool isCustomMode = false;


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
    if (CheckCollisionPointRec(GetMousePosition(), {50, 680, 180, 50}))
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            cout << "Simulation started" << endl;
            isSimulationRunning = true;
        }
    }
}

void stopSimulationButton()
{
    if (CheckCollisionPointRec(GetMousePosition(), {250, 680, 100, 50}))
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            cout << "Simulation stopped" << endl;
            isSimulationRunning = false;
        }
    }
}

void clearGridButton()
{
    if (CheckCollisionPointRec(GetMousePosition(), {370, 680, 130, 50}))
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            cout << "Grid cleared" << endl;
            for (int i = 0; i < 40; i++)
            {
                for (int j = 0; j < 30; j++)
                {
                    gridCells[i][j] = false;
                }
            }
        }
    }
}

void customButton()
{
    if (CheckCollisionPointRec(GetMousePosition(), {350, 620, 100, 50}))
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            isCustomMode = true;
            cout << "Custom button clicked" << endl;
        }
    }
}