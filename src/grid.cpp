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

int countLiveNeighbors(int row, int col)
{
    int count = 0;
    int rowOffsets[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int colOffsets[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i)
    {
        int newRow = row + rowOffsets[i];
        int newCol = col + colOffsets[i];

        if (newRow >= 0 && newRow < 40 && newCol >= 0 && newCol < 30)
        {
            if (gridCells[newRow][newCol] == 1)
            {
                count++;
            }
        }
    }

    return count;
}

void applyConwayRules()
{
    bool nextGrid[40][30];

    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            int liveNeighbors = countLiveNeighbors(i, j);

            if (gridCells[i][j] == 0 && liveNeighbors == 3)
            {
                nextGrid[i][j] = 1; // birth
            }
            else if (gridCells[i][j] == 1 && (liveNeighbors == 2 || liveNeighbors == 3))
            {
                nextGrid[i][j] = 1; // Stase
            }
            else
            {
                nextGrid[i][j] = 0; // dead
            }
        }
    }

    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            gridCells[i][j] = nextGrid[i][j];
        }
    }
}

