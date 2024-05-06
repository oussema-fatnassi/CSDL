#include <raylib.h>

void createGrid(int screenWidth, int screenHeight, int cellSize)
{
    int rows = screenHeight / cellSize;
    int columns = screenWidth / cellSize;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            DrawRectangle(j * cellSize +1, i * cellSize +1, cellSize-1, cellSize-1, WHITE);
        }
    }
};

void randomSpawn(int screenWidth, int screenHeight, int cellSize)
{
    int rows = screenHeight / cellSize;
    int columns = screenWidth / cellSize;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (GetRandomValue(0, 1) == 1)
            {
                DrawRectangle(j * cellSize +1, i * cellSize +1, cellSize-1, cellSize-1, BLACK);
            }
        }
    }
};