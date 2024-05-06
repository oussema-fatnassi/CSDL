#include "menu.hpp"
#include "grid.hpp"
#include <raylib.h>

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
        // randomSpawn(gridWidth, gridHeight, cellSize);
        createButton(50, 620, 100, 50, "Random");
        buttonIsClicked();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}