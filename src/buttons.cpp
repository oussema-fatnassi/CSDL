#include <raylib.h>
#include "buttons.hpp"
#include <iostream>
#include "grid.hpp"
#include "globals.hpp"
using namespace std;

bool isCustomMode = false;


void createButton(float x, float y, int width, int height, const char *text, Font font, int imageWidth, int imageHeight)
{
    Image buttonNormal = LoadImage("assets/images/button.png");
    Texture2D buttonNormalTexture = LoadTextureFromImage(buttonNormal);

    Image buttonHover = LoadImage("assets/images/buttonHover.png");
    Texture2D buttonHoverTexture = LoadTextureFromImage(buttonHover);

    // Define the source rectangle to use the entire button texture
    Rectangle sourceRec = { 0.0f, 0.0f, (float)buttonNormal.width, (float)buttonNormal.height };
    
    // Define the destination rectangle based on the specified width and height
    Rectangle destRec = { x, y, (float)width, (float)height };
    
    // Check if the mouse is hovering over the button
    if (CheckCollisionPointRec(GetMousePosition(), destRec))
    {
        // Draw the hovered button image texture
        DrawTexturePro(buttonHoverTexture, sourceRec, destRec, {0, 0}, 0, WHITE);
    }
    else
    {
        // Draw the normal button image texture
        DrawTexturePro(buttonNormalTexture, sourceRec, destRec, {0, 0}, 0, WHITE);
    }
    
    // Calculate the width of the text
    int textWidth = MeasureTextEx(font, text, 20, 0).x;
    
    // Calculate the x-coordinate to center the text horizontally
    float xPos = x + (width - textWidth) / 2;
    
    // Calculate the y-coordinate to center the text vertically
    float yPos = y + (height - 20) / 2; 

    // Draw the text using the specified font
    DrawTextEx(font, text, { xPos, yPos }, 20, 0, BLACK);
}




void clearGridButton()
{
    generationCount = 0;
    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            gridCells[i][j] = false;
        }
    }
}
