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

Image conway;
Image loneliness;
Image overcrowding;
Image reproduction;
Image stasis;
Image gameOfLifeExample;


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
    lonelinessTexture = LoadTextureFromImage(loneliness);
    overcrowding = LoadImage("assets/images/overcrowding.png");
    overcrowdingTexture = LoadTextureFromImage(overcrowding);
    reproduction = LoadImage("assets/images/reproduction.png");
    reproductionTexture = LoadTextureFromImage(reproduction);
    stasis = LoadImage("assets/images/stasis.png");
    stasisTexture = LoadTextureFromImage(stasis);
}

void unloadImages()
{
    UnloadTexture(conwayTexture);
    UnloadImage(conway);
    UnloadTexture(lonelinessTexture);
    UnloadImage(loneliness);
    UnloadTexture(overcrowdingTexture);
    UnloadImage(overcrowding);
    UnloadTexture(reproductionTexture);
    UnloadImage(reproduction);
    UnloadTexture(stasisTexture);
    UnloadImage(stasis);
}

void drawMainMenu()
{
    ClearBackground(GRAY);
    int textWidth = MeasureTextEx(font,"Game of Life", 90,0).x;
    float xPos = (GetScreenWidth() - textWidth) / 2;
    DrawTextEx(font, "Game of Life", { xPos, 100 }, 90, 0, BLACK);
    createButton(300, 300, 200, 50, "Introduction", font);
    createButton(300, 400, 200, 50, "Credits", font);
    createButton(300, 500, 200, 50, "Exit",font);
}

void drawIntroduction()
{
    ClearBackground(GRAY);
    DrawTexture(conwayTexture,20, 300, WHITE);
    DrawTexture(gameOfLifeExampleTexture, 385, 350, WHITE);
    int introductionTextWidth = MeasureTextEx(font,"Introduction", 70,0).x;
    float xPos = (GetScreenWidth() - introductionTextWidth) / 2;
    int firstLineTextWidth = MeasureTextEx(font, "Conway's Game of Life is a fascinating example of a cellular automaton,", 20, 0).x;
    float firstLineXPos = (GetScreenWidth() - firstLineTextWidth) / 2;
    int secondLineTextWidth = MeasureTextEx(font, "devised by the British mathematician John Horton Conway in 1970.", 20, 0).x;
    float secondLineXPos = (GetScreenWidth() - secondLineTextWidth) / 2;
    int thirdLineTextWidth = MeasureTextEx(font, "Despite its simplicity, this 'zero-player' game exhibits complex and unpredictable behavior.", 20, 0).x;
    float thirdLineXPos = (GetScreenWidth() - thirdLineTextWidth) / 2;

    DrawTextEx(font,"Introduction", {xPos, 100}, 70, 0, BLACK);
    DrawTextEx(font, "Conway's Game of Life is a fascinating example of a cellular automaton,", {firstLineXPos, 200}, 20, 0, WHITE);
    DrawTextEx(font, "devised by the British mathematician John Horton Conway in 1970.", {secondLineXPos, 230}, 20, 0, WHITE);
    DrawTextEx(font, "Despite its simplicity, this 'zero-player' game exhibits complex and unpredictable behavior.", {thirdLineXPos, 260}, 20, 0, WHITE);
    createButton(300, 700, 200, 50, "Skip", font);
    createButton(300, 760, 200, 50, "Back", font);
    createButton(300, 820, 200, 50, "Continue", font);
}

void drawRules()
{
    ClearBackground(GRAY);
    DrawTexture(lonelinessTexture, 20, 300, WHITE);
    DrawTexture(overcrowdingTexture, 20, 500, WHITE);
    DrawTexture(reproductionTexture, 400, 300, WHITE);
    DrawTexture(stasisTexture, 400, 500, WHITE);
}


void drawCredits()
{
    ClearBackground(GRAY);
    DrawText("Credits", 350, 100, 50, BLACK);
    DrawText("This game was created by the following people:", 50, 200, 20, WHITE);
    DrawText("Baptiste APPRIOU", 50, 250, 20, BLACK);
    DrawText("Ali Abakar ISSA", 50, 300, 20, BLACK);
    DrawText("Oussema FATNASSI", 50, 350, 20, BLACK);
    createButton(300, 600, 200, 50, "Back", font);
}

void drawCustomMode()
{
    ClearBackground(GRAY);
    createGrid(800, 800, 20);
    createButton(50, 880, 180, 50, "Start Simulation", font);
    createButton(250, 880, 100, 50, "Stop", font);
    createButton(370, 880, 130, 50, "Clear Grid", font);
    createButton(520, 880, 100, 50, "Quit", font);
    drawFPSSlider();
    drawZoomSlider();
}

void drawRandomMode()
{
    ClearBackground(GRAY);
    createGrid(800, 800, 20);
    createButton(50, 880, 100, 50, "Reroll", font);
    createButton(170, 880, 180, 50, "Start Simulation", font);
    createButton(370, 880, 100, 50, "Stop", font);
    createButton(490, 880, 130, 50, "Clear Grid", font);
    createButton(650, 880, 100, 50, "Quit", font);
    drawFPSSlider();
}

void drawDefaultMode()
{
    ClearBackground(GRAY);
    createGrid(800, 800, 20);
    createButton(50, 880, 180, 50, "Start Simulation", font);
    createButton(250, 880, 100, 50, "Stop", font);
    createButton(370, 880, 130, 50, "Clear Grid", font);
    createButton(520, 880, 100, 50, "Quit", font);
    drawFPSSlider();

}
void drawModeMenu()
{
    createButton(350, 200, 100, 50, "Random", font);
    createButton(350, 300, 100, 50, "Default", font);
    createButton(350, 400, 100, 50, "Custom", font);
    createButton(350, 550, 100, 50, "Back", font);
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