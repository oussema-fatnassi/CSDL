#include <raylib.h>
#include "buttons.hpp"
#include "grid.hpp"
#include "globals.hpp"
#include "menu.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#define FILTER_BILINEAR 2


Font font;
Image icon;

void InitializeResources() {
    font = LoadFontEx("assets/fonts/AmericanTypewriterRegular.ttf", 64, 0, 0);
    SetTextureFilter(font.texture, 2);
    icon = LoadImage("assets/images/icon.png");
    
}

bool isSimulationRunning = false;
Menu currentMenu = MAIN_MENU;

int main() {
    const int screenWidth = 800;
    const int screenHeight = 1000;
    
    // Image icon = LoadImage("assets/images/icon.png");
    // SetWindowIcon(icon);
    // UnloadImage(icon);

    InitWindow(screenWidth, screenHeight, "Game of Life");
    InitializeResources();
    SetWindowIcon(icon);
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
    UnloadFont(font);
    UnloadImage(icon);

    CloseWindow();
    return 0;
}