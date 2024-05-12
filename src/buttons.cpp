#include <raylib.h>
#include "buttons.hpp"
#include <iostream>
#include "grid.hpp"
#include "globals.hpp"
using namespace std;

void createButton(float x, float y, int width, int height, const char *text, Font font, int imageWidth, int imageHeight)            // Create button function
{
    Image buttonNormal = LoadImage("assets/images/button.png");                                                                     // Load normal button image and load texture
    Texture2D buttonNormalTexture = LoadTextureFromImage(buttonNormal);

    Image buttonHover = LoadImage("assets/images/buttonHover.png");                                                                 // Load hover button image and load texture
    Texture2D buttonHoverTexture = LoadTextureFromImage(buttonHover);

    Rectangle sourceRec = { 0.0f, 0.0f, (float)buttonNormal.width, (float)buttonNormal.height };                                    // Define the destination rectangle based on the specified width and height
    
    Rectangle destRec = { x, y, (float)width, (float)height };                                                                      // Define the destination rectangle based on the specified width and height
    
    
    if (CheckCollisionPointRec(GetMousePosition(), destRec))                                                                        // Check if the mouse is hovering over the button
    {
        DrawTexturePro(buttonHoverTexture, sourceRec, destRec, {0, 0}, 0, WHITE);                                                   // Draw the hovered button image texture
    }
    else
    {
        DrawTexturePro(buttonNormalTexture, sourceRec, destRec, {0, 0}, 0, WHITE);                                                  // Draw the normal button image texture                  
    }
    
    int textWidth = MeasureTextEx(font, text, 20, 0).x;                                                                             // Calculate the width of the text
    
    float xPos = x + (width - textWidth) / 2;                                                                                       // Calculate the x-coordinate to center the text horizontally
    
    float yPos = y + (height - 20) / 2;                                                                                             // Calculate the y-coordinate to center the text vertically

    DrawTextEx(font, text, { xPos, yPos }, 20, 0, BLACK);                                                                           // Draw the text                   
}

void clearGridButton()                                                                                                              // Clear the grid
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
