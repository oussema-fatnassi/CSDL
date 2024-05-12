#include <raylib.h>
#include <fstream>
#include "globals.hpp"
#include "menu.hpp"
using namespace std;
bool gridCells[40][40] = {{false}};

void saveGridToFile()
{
    std::ofstream file("matrix.txt");

    if (file.is_open())
    {
        for (int i = 0; i < 40; i++)
        {
            for (int j = 0; j < 40; j++)
            {
                file << gridCells[i][j] << " ";
            }
            file << "\n";
        }

        file.close();
    }
}

void createGrid(int screenWidth, int screenHeight, int cellSize)
{
    int rows = screenHeight / (cellSize/zoomLevel);
    int columns = screenWidth / (cellSize/zoomLevel);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (gridCells[i][j])
            {
                DrawRectangle(j * (cellSize/zoomLevel) + 1, i * (cellSize/zoomLevel) + 1, (cellSize/zoomLevel) - 1, (cellSize/zoomLevel) - 1, BLACK);
            }
            else
            {
                DrawRectangle(j * (cellSize/zoomLevel) + 1, i * (cellSize/zoomLevel) + 1, (cellSize/zoomLevel) - 1, (cellSize/zoomLevel) - 1, WHITE);
            }
        }
    }
}


void randomSpawn(int screenWidth, int screenHeight, int cellSize)
{
    int rows = 800 / cellSize;
    int columns = 800 / cellSize;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            gridCells[i][j] = GetRandomValue(0, 3) == 1;
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

        if (newRow >= 0 && newRow < 40 && newCol >= 0 && newCol < 40)
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
    bool nextGrid[40][40];

    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 40; j++)
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
    saveGridToFile();
    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            gridCells[i][j] = nextGrid[i][j];
        }
    }
}

void customGridSpawn() {
    int cellSize = 20;
    int rows = 800 / cellSize;
    int columns = 800 / cellSize;

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) 
    {
        Vector2 mousePosition = GetMousePosition();
        int row = mousePosition.y / cellSize;
        int column = mousePosition.x / cellSize;

        if (row >= 0 && row < rows && column >= 0 && column < columns) {
            gridCells[row][column] = true; // Change to black
        }
    } 

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
    {
        Vector2 mousePosition = GetMousePosition();
        int row = mousePosition.y / cellSize;
        int column = mousePosition.x / cellSize;

        if (row >= 0 && row < rows && column >= 0 && column < columns) {
            gridCells[row][column] = false; // Change to white
        }
    } 
}

void loadGridFromFile()
{
    ifstream file("matrix.txt");

    if (file.is_open())
    {
        for (int i = 0; i < 40; i++)
        {
            for (int j = 0; j < 40; j++)
            {
                file >> gridCells[i][j];
            }
        }
        file.close();
    }
}