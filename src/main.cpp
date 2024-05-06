#include "menu.hpp"
#include "grid.hpp"
#include <raylib.h>
#include "globals.hpp"

bool isSimulationRunning = false;
int main() {
    const int screenWidth = 800;
    const int screenHeight = 800;
    const int gridWidth = 800;
    const int gridHeight = 600;
    const int cellSize = 20;

    InitWindow(screenWidth, screenHeight, "Game of Life");

    SetTargetFPS(5);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GRAY);
        createGrid(gridWidth, gridHeight, cellSize);
        createButton(50, 620, 100, 50, "Random");
        createButton(200, 620, 100, 50, "Default");
        createButton(350, 620, 180, 50, "Start Simulation");
        spawnRandomButton();
        startSimulationButton();

        if (isSimulationRunning) {
            applyConwayRules();
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}