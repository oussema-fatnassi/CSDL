#include <iostream>
#include <raylib.h>
#include "menu.hpp"
#include "buttons.hpp"
#include "globals.hpp"
#include "grid.hpp"
#include "customize.hpp"
using namespace std;

int fpsValues[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                   11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                   21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                   31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                   41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
                   51, 52, 53, 54, 55, 56, 57, 58, 59, 60,};

Texture2D conwayTexture;
Texture2D lonelinessTexture;
Texture2D overcrowdingTexture;
Texture2D reproductionTexture;
Texture2D stasisTexture;
Texture2D gameOfLifeExampleTexture;
Texture2D gliderTexture;
Texture2D blinkerTexture;
Texture2D toadTexture;
Texture2D blockTexture; 

Image conway;
Image loneliness;
Image overcrowding;
Image reproduction;
Image stasis;
Image gameOfLifeExample;
Image glider;
Image blinker;
Image toad;
Image block;


int zoomLevel = 1;

void loadImages()
{
    conway = LoadImage("assets/images/conway.png");
    ImageResize(&conway, 348, 310);
    conwayTexture = LoadTextureFromImage(conway);
    gameOfLifeExample = LoadImage("assets/images/GameLifeExample.png");
    ImageResize(&gameOfLifeExample, 400, 230);
    gameOfLifeExampleTexture = LoadTextureFromImage(gameOfLifeExample);
    loneliness = LoadImage("assets/images/loneliness.png");
    ImageResize(&loneliness, 175, 80);
    lonelinessTexture = LoadTextureFromImage(loneliness);
    overcrowding = LoadImage("assets/images/overcrowding.png");
    ImageResize(&overcrowding, 175, 80);
    overcrowdingTexture = LoadTextureFromImage(overcrowding);
    reproduction = LoadImage("assets/images/reproduction.png");
    ImageResize(&reproduction, 175, 80);
    reproductionTexture = LoadTextureFromImage(reproduction);
    stasis = LoadImage("assets/images/stasis.png");
    ImageResize(&stasis, 175, 80);
    stasisTexture = LoadTextureFromImage(stasis);
    glider = LoadImage("assets/images/glider.png");
    ImageResize(&glider, 460, 90);
    gliderTexture = LoadTextureFromImage(glider);
    blinker = LoadImage("assets/images/blinker.png");
    ImageResize(&blinker, 140, 70);
    blinkerTexture = LoadTextureFromImage(blinker);
    toad = LoadImage("assets/images/toad.png");
    ImageResize(&toad, 140, 70);
    toadTexture = LoadTextureFromImage(toad);
    block = LoadImage("assets/images/block.png");
    ImageResize(&block, 70, 70);
    blockTexture = LoadTextureFromImage(block);
}

void unloadImages()
{
    UnloadTexture(conwayTexture);
    UnloadImage(conway);
    UnloadTexture(gameOfLifeExampleTexture);
    UnloadImage(gameOfLifeExample);
    UnloadTexture(lonelinessTexture);
    UnloadImage(loneliness);
    UnloadTexture(overcrowdingTexture);
    UnloadImage(overcrowding);
    UnloadTexture(reproductionTexture);
    UnloadImage(reproduction);
    UnloadTexture(stasisTexture);
    UnloadImage(stasis);
    UnloadTexture(gliderTexture);
    UnloadImage(glider);
    UnloadTexture(blinkerTexture);
    UnloadImage(blinker);
    UnloadTexture(toadTexture);
    UnloadImage(toad);
    UnloadTexture(blockTexture);
    UnloadImage(block);
}

void drawMainMenu()
{
    ClearBackground(GRAY);
    int textWidth = MeasureTextEx(font,"Game of Life", 90,0).x;
    float xPos = (GetScreenWidth() - textWidth) / 2;
    DrawTextEx(font, "Game of Life", { xPos, 100 }, 90, 0, BLACK);
    createButton(300, 300, 200, 50, "Introduction", font, 200, 50);
    createButton(300, 400, 200, 50, "Credits", font, 200, 50);
    createButton(300, 500, 200, 50, "Exit",font, 200, 50);
}

void drawIntroduction()
{
    ClearBackground(GRAY);
    DrawTexture(conwayTexture,20, 300, WHITE);
    DrawTexture(gameOfLifeExampleTexture, 385, 350, WHITE);
    int introductionTextWidth = MeasureTextEx(font,"Introduction", 50,0).x;
    float xPos = (GetScreenWidth() - introductionTextWidth) / 2;
    int firstLineTextWidth = MeasureTextEx(font, "Conway's Game of Life is a fascinating example of a cellular automaton,", 20, 0).x;
    float firstLineXPos = (GetScreenWidth() - firstLineTextWidth) / 2;
    int secondLineTextWidth = MeasureTextEx(font, "devised by the British mathematician John Horton Conway in 1970.", 20, 0).x;
    float secondLineXPos = (GetScreenWidth() - secondLineTextWidth) / 2;
    int thirdLineTextWidth = MeasureTextEx(font, "Despite its simplicity, this 'zero-player' game exhibits complex and unpredictable behavior.", 20, 0).x;
    float thirdLineXPos = (GetScreenWidth() - thirdLineTextWidth) / 2;

    DrawTextEx(font,"Introduction", {xPos, 20}, 50, 0, BLACK);
    DrawTextEx(font, "Conway's Game of Life is a fascinating example of a cellular automaton,", {firstLineXPos, 200}, 20, 0, WHITE);
    DrawTextEx(font, "devised by the British mathematician John Horton Conway in 1970.", {secondLineXPos, 230}, 20, 0, WHITE);
    DrawTextEx(font, "Despite its simplicity, this 'zero-player' game exhibits complex and unpredictable behavior.", {thirdLineXPos, 260}, 20, 0, WHITE);
    createButton(300, 700, 200, 50, "Skip", font, 200, 50);
    createButton(300, 760, 200, 50, "Back", font, 200, 50);
    createButton(300, 820, 200, 50, "Continue", font, 200, 50);
}

void drawCellTypes()
{
    ClearBackground(WHITE);
    int cellTypesTextWidth = MeasureTextEx(font, "Cell Types", 50, 0).x;
    float cellTypesXPos = (GetScreenWidth() - cellTypesTextWidth) / 2;
    DrawTextEx(font, "Cell Types", {cellTypesXPos, 20}, 50, 0, BLACK);
    DrawTexture(blockTexture, 70, 140, WHITE);
    DrawTexture(blinkerTexture, 70, 270, WHITE);
    DrawTexture(toadTexture, 70, 400, WHITE);
    DrawTexture(gliderTexture, 70, 530, WHITE);
    createButton(300, 760, 200, 50, "Back", font, 200, 50);
    createButton(300, 820, 200, 50, "Continue", font, 200, 50);

    DrawTextEx(font, "BLOCK:", {20, 90}, 20, 0, BLACK);
    DrawTextEx(font, "A still life pattern that does not change from one generation to the next", {20, 110}, 20, 0, BLACK);
    DrawTextEx(font, "BLINKER:", {20, 220}, 20, 0, BLACK);
    DrawTextEx(font, "A period 2 oscillator that alternates between two states every generation", {20, 240}, 20, 0, BLACK);
    DrawTextEx(font, "TOAD:", {20, 350}, 20, 0, BLACK);
    DrawTextEx(font, "A period 2 oscillator that alternates between two states every generation", {20, 370}, 20, 0, BLACK);
    DrawTextEx(font, "GLIDER:", {20, 480}, 20, 0, BLACK);
    DrawTextEx(font, "A spaceship that moves diagonally across the grid", {20, 500}, 20, 0, BLACK);
    DrawTextEx(font, "OSCILLATOR CELLS:", {20, 650}, 20, 0, BLACK);
    DrawTextEx(font, "These cells form patterns that alternate between two or more states, like blinkers and toads", {20, 670}, 20, 0, BLACK);
    DrawTextEx(font, "SPACESHIP CELLS:", {20, 720}, 20, 0, BLACK);
    DrawTextEx(font, "These cells move across the grid, like gliders", {20, 740}, 20, 0, BLACK);
}

void drawRules()
{   
    int rulesTextWidth = MeasureTextEx(font, "Rules", 50, 0).x;
    float rulesXPos = (GetScreenWidth() - rulesTextWidth) / 2;
    DrawTextEx(font, "Rules", {rulesXPos, 20}, 50, 0, BLACK);
    DrawTextEx(font, "LONELINESS:", {280, 140}, 20, 0, BLACK);
    DrawTextEx(font, "A cell with less than 2 adjoining cells dies", {280, 160}, 20, 0, BLACK);
    DrawTextEx(font, "OVERCROWDING:", {280, 270}, 20, 0, BLACK);
    DrawTextEx(font, "A cell with more than 3 adjoining cells dies", {280, 290}, 20, 0, BLACK);
    DrawTextEx(font, "REPRODUCTION:", {280, 400}, 20, 0, BLACK);
    DrawTextEx(font, "An empty cell with 3 adjoining cells becomes alive", {280, 420}, 20, 0, BLACK);
    DrawTextEx(font, "STASIS:", {280, 530}, 20, 0, BLACK);
    DrawTextEx(font, "A cell with exactly 2 adjoining cells survives", {280, 550}, 20, 0, BLACK);
    ClearBackground(WHITE);
    DrawTexture(lonelinessTexture, 70, 120, WHITE);
    DrawTexture(overcrowdingTexture, 70, 250, WHITE);
    DrawTexture(reproductionTexture, 70, 380, WHITE);
    DrawTexture(stasisTexture, 70, 510, WHITE);
    createButton(300, 700, 200, 50, "Skip", font, 200, 50);
    createButton(300, 760, 200, 50, "Back", font, 200, 50);
    createButton(300, 820, 200, 50, "Continue", font, 200, 50);
}


void drawCredits()
{
    ClearBackground(GRAY);
    DrawText("Credits", 350, 100, 50, BLACK);
    DrawText("This game was created by the following people:", 50, 200, 20, WHITE);
    DrawText("Baptiste APPRIOU", 50, 250, 20, BLACK);
    DrawText("Ali Abakar ISSA", 50, 300, 20, BLACK);
    DrawText("Oussema FATNASSI", 50, 350, 20, BLACK);
    createButton(300, 600, 200, 50, "Back", font, 200, 50);
}

void drawCustomMode()
{
    ClearBackground(GRAY);
    createGrid(800, 800, 20);
    createButton(50, 880, 180, 50, "Start Simulation", font, 200, 50);
    createButton(250, 880, 100, 50, "Stop", font, 100, 50);
    createButton(370, 880, 130, 50, "Clear Grid", font, 130, 50);
    createButton(520, 880, 100, 50, "Quit", font, 100, 50);
    DrawTextEx(font, "Generation: ", {400, 950}, 20, 0, BLACK);
    DrawTextEx(font, std::to_string(generationCount).c_str(), {520, 950}, 20, 0, BLACK); // Draw the generation count
    drawFPSSlider();
    // drawZoomSlider();
}

void drawRandomMode()
{
    ClearBackground(GRAY);
    createGrid(800, 800, 20);
    createButton(50, 880, 100, 50, "Reroll", font, 100, 50);
    createButton(170, 880, 180, 50, "Start Simulation", font, 200, 50);
    createButton(370, 880, 100, 50, "Stop", font, 100, 50);
    createButton(490, 880, 130, 50, "Clear Grid", font, 130, 50);
    createButton(650, 880, 100, 50, "Quit", font, 100, 50);
    DrawTextEx(font, "Generation: ", {400, 950}, 20, 0, BLACK);
    DrawTextEx(font, std::to_string(generationCount).c_str(), {520, 950}, 20, 0, BLACK); // Draw the generation count
    drawFPSSlider();
}

void drawDefaultMode()
{
    ClearBackground(GRAY);
    createGrid(800, 800, 20);
    createButton(50, 880, 180, 50, "Start Simulation", font, 200, 50);
    createButton(250, 880, 100, 50, "Stop", font, 100, 50);
    createButton(370, 880, 130, 50, "Clear Grid", font, 130, 50);
    createButton(520, 880, 100, 50, "Quit", font, 100, 50);
    DrawTextEx(font, "Generation: ", {400, 950}, 20, 0, BLACK);
    DrawTextEx(font, std::to_string(generationCount).c_str(), {520, 950}, 20, 0, BLACK); // Draw the generation count
    drawFPSSlider();
}
void drawModeMenu()
{
    createButton(350, 200, 100, 50, "Random", font, 100, 50);
    createButton(350, 300, 100, 50, "Default", font, 100, 50);
    createButton(350, 400, 100, 50, "Custom", font, 100, 50);
    createButton(350, 550, 100, 50, "Back", font, 100, 50);
}

void menuInput()
{
    if (currentMenu == MAIN_MENU)
    {
        if (CheckCollisionPointRec(GetMousePosition(), {300, 300, 200, 50}))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = INTRODUCTION;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 600, 200, 50}))   
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                drawModeMenu();
                currentMenu = MODE_MENU;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 400, 200, 50}))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = CREDITS;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 500, 200, 50}))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                CloseWindow();
            }
        }
    }
    else if (currentMenu == INTRODUCTION)
    {
        if (CheckCollisionPointRec(GetMousePosition(), {300, 700, 200, 50}))    //skip button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = MODE_MENU;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 760, 200, 50}))   // back button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = MAIN_MENU;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 820, 200, 50}))   // continue button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                drawRules();
                currentMenu = RULES;
            }
        }
    }
    else if (currentMenu == RULES)
    {
        if (CheckCollisionPointRec(GetMousePosition(), {300, 700, 200, 50}))    //skip button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = MODE_MENU;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 760, 200, 50}))   // back button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = INTRODUCTION;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 820, 200, 50}))   // continue button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                drawCellTypes();
                currentMenu = CELL_TYPES;
            }
        }
    }
    else if (currentMenu == CELL_TYPES)
    {
        if (CheckCollisionPointRec(GetMousePosition(), {300, 820, 200, 50}))    //continue button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = MODE_MENU;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 760, 200, 50}))   // back button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = RULES;
            }
        }
    }
    else if (currentMenu == CREDITS)
    {
        if (CheckCollisionPointRec(GetMousePosition(), {300, 600, 200, 50}))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                drawMainMenu();
                currentMenu = MAIN_MENU;
            }
        }
    }
}

void modeInput()
{
    if (currentMenu == MODE_MENU)
    {
        if (CheckCollisionPointRec(GetMousePosition(), {350, 400, 100, 50}))    //Custom mode button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                drawCustomMode();
                currentMenu = CUSTOM_MODE;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {350, 200, 100, 50}))    //Random mode button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                drawRandomMode();
                currentMenu = RANDOM_MODE;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {350, 300, 100, 50}))    //Default mode button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                drawDefaultMode();
                loadGridFromFile();
                currentMenu = DEFAULT_MODE;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {350, 550, 100, 50}))       //Back button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {   
                drawMainMenu();
                currentMenu = MAIN_MENU;
            }
        }
    }
    else if (currentMenu == CUSTOM_MODE) {
        customGridSpawn();

        if (CheckCollisionPointRec(GetMousePosition(), {50, 880, 180, 50}))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                isSimulationRunning = true;
            }
        }
        if(isSimulationRunning)
        {
            applyConwayRules();
        }
        
        if (CheckCollisionPointRec(GetMousePosition(), {250, 880, 100, 50}))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                isSimulationRunning = false;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {370, 880, 130, 50}))       //Clear grid button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {   
                isSimulationRunning = false;
                clearGridButton();
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {520, 880, 100, 50}))       //Quit button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {   
                clearGridButton();
                isSimulationRunning = false;
                drawMainMenu();
                currentMenu = MAIN_MENU;
            }
        }
        if (CheckCollisionPointRec(GetMousePosition(), {70, 950, 200, 20})) // FPS slider
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                int mouseX = GetMouseX();

                int fpsIndex = Clamp((mouseX - 70) / (200 / 60), 0, 59);
                int newFPS = fpsValues[fpsIndex];
                SetTargetFPS(newFPS);
            }

        }
        
    }
    else if (currentMenu == RANDOM_MODE)
    {
        if (CheckCollisionPointRec(GetMousePosition(), {50, 880, 100, 50}))    //Reroll button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                isSimulationRunning = false;
                clearGridButton();
                randomSpawn(800, 600, 20);
            }
        }
        if (CheckCollisionPointRec(GetMousePosition(), {170, 880, 180, 50}))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                isSimulationRunning = true;
            }
        }
        if(isSimulationRunning)
        {
            applyConwayRules();
        }
        
        if (CheckCollisionPointRec(GetMousePosition(), {370, 880, 130, 50}))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                isSimulationRunning = false;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {520, 880, 100, 50}))       //Clear grid button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {   
                isSimulationRunning = false;
                clearGridButton();
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {650, 880, 100, 50}))       //Quit button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {   
                isSimulationRunning = false;
                clearGridButton();
                drawMainMenu();
                currentMenu = MAIN_MENU;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {70, 950, 200, 20})) // FPS slider
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                int mouseX = GetMouseX();

                int fpsIndex = Clamp((mouseX - 70) / (200 / 60), 0, 59);
                int newFPS = fpsValues[fpsIndex];
                SetTargetFPS(newFPS);
            }
        }
    }
    else if (currentMenu == DEFAULT_MODE)
        {
            if (CheckCollisionPointRec(GetMousePosition(), {50, 880, 180, 50}))
            {
                if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                {
                    isSimulationRunning = true;
                }
            }
            if(isSimulationRunning)
            {
                applyConwayRules();
            }
            
            if (CheckCollisionPointRec(GetMousePosition(), {250, 880, 100, 50}))
            {
                if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                {
                    isSimulationRunning = false;
                }
            }
            else if (CheckCollisionPointRec(GetMousePosition(), {370, 880, 130, 50}))       //Clear grid button
            {
                if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                {   
                    isSimulationRunning = false;
                    clearGridButton();
                }
            }
            else if (CheckCollisionPointRec(GetMousePosition(), {520, 880, 100, 50}))       //Quit button
            {
                if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                {   
                    isSimulationRunning = false;
                    clearGridButton();
                    drawMainMenu();
                    currentMenu = MAIN_MENU;
                }
            }
            else if (CheckCollisionPointRec(GetMousePosition(), {70, 950, 200, 20})) // FPS slider
            {
                if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                {
                    int mouseX = GetMouseX();

                    int fpsIndex = Clamp((mouseX - 70) / (200 / 60), 0, 59);
                    int newFPS = fpsValues[fpsIndex];
                    SetTargetFPS(newFPS);
                }
            }
        }
}