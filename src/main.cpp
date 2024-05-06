#include "menu.hpp"
#include <raylib.h>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 800;
    const int gridWidth = 800;
    const int gridHeight = 600;
    const int cellSize = 20;

    InitWindow(screenWidth, screenHeight, "Game of Life");

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        createGrid(gridWidth, gridHeight, cellSize);
        createButton(50, 620, 100, 50, "Start");
        EndDrawing();
    }

    CloseWindow();
    return 0;
}