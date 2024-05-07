#include "menu.hpp"
#include "grid.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <raylib.h>
#include "globals.hpp"

bool isSimulationRunning = false;
int main() {
    const int screenWidth = 800;
    const int screenHeight = 1000;
    const int gridWidth = 800;
    const int gridHeight = 800;
    const int cellSize = 20;

    InitWindow(screenWidth, screenHeight, "Game of Life");

    SetTargetFPS(10);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GRAY);
        createGrid(gridWidth, gridHeight, cellSize);
        createButton(50, 820, 100, 50, "Random");
        createButton(200, 820, 100, 50, "Default");
        createButton(350, 820, 100, 50, "Custom");
        createButton(50, 880, 180, 50, "Start Simulation");
        createButton(250, 880, 100, 50, "Stop");
        createButton(370, 880, 130, 50, "Clear Grid");
        spawnRandomButton();
        startSimulationButton();
        stopSimulationButton();
        clearGridButton();
        customButton();
        customGridSpawn();

        if (isSimulationRunning) {
            applyConwayRules();
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}