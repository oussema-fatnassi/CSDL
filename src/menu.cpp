#include <raylib.h>
#include "menu.hpp"
#include <iostream>
#include "grid.hpp"
using namespace std;

void createButton(int x, int y, int width, int height, const char *text)
{
    DrawRectangle(x, y, width, height, WHITE);
    DrawText(text, x + 10, y + 15, 20, BLACK);
}

void buttonIsClicked()
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