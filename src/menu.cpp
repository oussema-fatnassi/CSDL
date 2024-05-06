#include <raylib.h>
#include "menu.hpp"

void createGrid(int screenWidth, int screenHeight, int cellSize)
{
    int rows = screenHeight / cellSize;
    int columns = screenWidth / cellSize;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            DrawRectangle(j * cellSize +1, i * cellSize +1, cellSize-1, cellSize-1, GRAY);
        }
    }
};

void createButton(int x, int y, int width, int height, const char *text)
{
    DrawRectangle(x, y, width, height, GRAY);
    DrawText(text, x + 10, y + 10, 20, WHITE);
}