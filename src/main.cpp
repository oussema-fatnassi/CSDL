#include <raylib.h>
#include "buttons.hpp"
#include "grid.hpp"
#include "globals.hpp"
#include "menu.hpp"

bool isSimulationRunning = false;
Menu currentMenu = MAIN_MENU;

int main() {
    const int screenWidth = 800;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Game of Life");

    SetTargetFPS(5);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GRAY);

        switch (currentMenu) {
        case MAIN_MENU:
            drawMainMenu();
            break;
        case INTRODUCTION:
            drawIntroduction();
            break;
        case CREDITS:
            drawCredits();
            break;
        case MODE_MENU:
            drawModeMenu();
            break;
        case CUSTOM_MODE:
            drawCustomMode();
            break;
        case RANDOM_MODE:
            drawRandomMode();
            break;
        case DEFAULT_MODE:
            drawDefaultMode();
            break;
        default:
            break;
    }
        menuInput();
        modeInput();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}