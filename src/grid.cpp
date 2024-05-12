#include <raylib.h>
#include <fstream>
#include "globals.hpp"
#include "menu.hpp"
#include <iostream>
using namespace std;
bool gridCells[40][40] = {{false}};
int generationCount = 0;

void saveGridToFile()                                                           // Save the grid in the file save.txt
{
    std::ofstream file("assets/matrices/save.txt");

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

void createGrid(int screenWidth, int screenHeight, int cellSize)                // Create grid with the specified dimensions 
{
    int rows = screenHeight / (cellSize/zoomLevel);
    int columns = screenWidth / (cellSize/zoomLevel);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (gridCells[i][j])                                                // If the cell is alive, draw it in black
            {
                DrawRectangle(j * (cellSize/zoomLevel) + 1, i * (cellSize/zoomLevel) + 1, (cellSize/zoomLevel) - 1, (cellSize/zoomLevel) - 1, BLACK);
            }
            else                                                                // If the cell is dead, draw it in white 
            {
                DrawRectangle(j * (cellSize/zoomLevel) + 1, i * (cellSize/zoomLevel) + 1, (cellSize/zoomLevel) - 1, (cellSize/zoomLevel) - 1, WHITE);
            }
        }
    }
}


void randomSpawn(int screenWidth, int screenHeight, int cellSize)               // Randomly spawn the cells in the grid 
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

int countLiveNeighbors(int row, int col)                                        // Count the number of live neighbors of the cell 
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

void applyConwayRules()                                                         // Apply the rules of the Game of Life
{
    generationCount++;
    bool nextGrid[40][40];

    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            int liveNeighbors = countLiveNeighbors(i, j);

            if (gridCells[i][j] == 0 && liveNeighbors == 3)                     // If the cell is dead and has 3 live neighbors, it will be alive
            {
                nextGrid[i][j] = 1; // birth
            }
            else if (gridCells[i][j] == 1 && (liveNeighbors == 2 || liveNeighbors == 3))        // If the cell is alive and has 2 or 3 live neighbors, it will be alive 
            {
                nextGrid[i][j] = 1; // Stase
            }
            else                                                                // If the cell is alive and has less than 2 or more than 3 live neighbors, it will be dead
            {
                nextGrid[i][j] = 0; // dead
            }
        }
    }
    saveGridToFile();
    for (int i = 0; i < 40; i++)                                                // Update the grid with the next grid
    {
        for (int j = 0; j < 40; j++)
        {
            gridCells[i][j] = nextGrid[i][j];
        }
    }
}

void customGridSpawn() {                                                        // Custom grid spawn with possibility to change the cell state with the mouse
    int cellSize = 20;
    int rows = 800 / cellSize;
    int columns = 800 / cellSize;

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) 
    {
        Vector2 mousePosition = GetMousePosition();
        int row = mousePosition.y / cellSize;
        int column = mousePosition.x / cellSize;

        if (row >= 0 && row < rows && column >= 0 && column < columns) {        // If the mouse is clicked on a cell, change its state
            gridCells[row][column] = true;                                      // Change to black
        }
    } 

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
    {
        Vector2 mousePosition = GetMousePosition();
        int row = mousePosition.y / cellSize;
        int column = mousePosition.x / cellSize;

        if (row >= 0 && row < rows && column >= 0 && column < columns) {        // If the mouse is pressed on a cell, change its state
            gridCells[row][column] = false;                                     // Change to white
        }
    } 
}

void loadGridFromFile(const char* filename) {                                   // Load the grid from the specified file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    int row = 0;
    int col = 0;
    while (file >> gridCells[row][col]) {
        col++;
        if (col >= 40) {
            col = 0;
            row++;
        }
    }
    file.close();
}