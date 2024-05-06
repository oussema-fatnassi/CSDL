#include <raylib.h>

bool gridCells[40][30];

void createGrid(int screenWidth, int screenHeight, int cellSize)
{
    int rows = screenHeight / cellSize;
    int columns = screenWidth / cellSize;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (gridCells[i][j])
            {
                DrawRectangle(j * cellSize + 1, i * cellSize + 1, cellSize - 1, cellSize - 1, BLACK);
            }
            else
            {
                DrawRectangle(j * cellSize + 1, i * cellSize + 1, cellSize - 1, cellSize - 1, WHITE);
            }
        }
    }
}


void randomSpawn(int screenWidth, int screenHeight, int cellSize)
{
    int rows = screenHeight / cellSize;
    int columns = screenWidth / cellSize;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            gridCells[i][j] = GetRandomValue(0, 1) == 1;
        }
    }
}