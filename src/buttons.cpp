#include <raylib.h>
#include "buttons.hpp"
#include <iostream>
#include "grid.hpp"
#include "globals.hpp"
using namespace std;

bool isCustomMode = false;


void createButton(float x, float y, int width, int height, const char *text, Font font)
{
    DrawRectangle(x, y, width, height, WHITE);
    
    // Calculate the width of the text
    int textWidth = MeasureTextEx(font, text, 20, 0).x;
    
    // Calculate the x-coordinate to center the text horizontally
    float xPos = x + (width - textWidth) / 2;
    
    // Calculate the y-coordinate to center the text vertically
    float yPos = y + (height - 20) / 2; // Assuming font size is 20

    // Draw the text using the specified font
    DrawTextEx(font, text, { xPos, yPos }, 20, 0, BLACK);
}


void clearGridButton()
{
    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            gridCells[i][j] = false;
        }
    }
}
