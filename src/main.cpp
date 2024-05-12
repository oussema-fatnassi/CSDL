#include <raylib.h>
#include "buttons.hpp"
#include "grid.hpp"
#include "globals.hpp"
#include "menu.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#define FILTER_BILINEAR 2                                                               // Define filter bilinear for font texture 

Font font;

void loadFont() {                                                                       // Load font
    font = LoadFontEx("assets/fonts/AmericanTypewriterRegular.ttf", 64, 0, 0);
    SetTextureFilter(font.texture, 2);
}

bool isSimulationRunning = false;                                                       // Initialisation of Simulation state
Menu currentMenu = MAIN_MENU;                                                           // Initialisation of Menu state
Color backgroundColor = {0,28,48,120};                                                  // Initialisation of Background color

int main() {
    const int screenWidth = 800;
    const int screenHeight = 1000;
    
    InitWindow(screenWidth, screenHeight, "Game of Life");
    loadFont();
    loadImages();
    SetTargetFPS(15);
    while (!WindowShouldClose()) {
        BeginDrawing();

        switch (currentMenu) {                                                          // Switch case for menu state based on currentMenu
        case MAIN_MENU:
            drawMainMenu();
            break;
        case INTRODUCTION:
            drawIntroduction();
            break;
        case RULES:
            drawRules();
            break;
        case CELL_TYPES:
            drawCellTypes();
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
    UnloadFont(font);                                                                                   // Unload font to free memory
    unloadImages();                                                                                     // Unload images to free memory
    CloseWindow();
    return 0;
}