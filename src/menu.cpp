#include <iostream>
#include <raylib.h>
#include "menu.hpp"
#include "buttons.hpp"
#include "globals.hpp"
#include "grid.hpp"
#include "customize.hpp"
using namespace std;

int fpsValues[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,                       // Array of FPS values
                   11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                   21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                   31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                   41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
                   51, 52, 53, 54, 55, 56, 57, 58, 59, 60,};

Texture2D conwayTexture;                                                // 2DTextures for the menu
Texture2D lonelinessTexture;
Texture2D overcrowdingTexture;
Texture2D reproductionTexture;
Texture2D stasisTexture;
Texture2D gameOfLifeExampleTexture;
Texture2D gliderTexture;
Texture2D blinkerTexture;
Texture2D toadTexture;
Texture2D blockTexture;
Texture2D backgroundTexture; 
Texture2D background1Texture; 

Image conway;                                                           // Images for the menu
Image loneliness;
Image overcrowding;
Image reproduction;
Image stasis;
Image gameOfLifeExample;
Image glider;
Image blinker;
Image toad;
Image block;
Image background;
Image background1;

int zoomLevel = 1;

void loadImages()                                                       // Load images and resize them
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
    background = LoadImage("assets/images/background.png");
    ImageRotate(&background, 90);
    backgroundTexture = LoadTextureFromImage(background);
    background1 = LoadImage("assets/images/background1.png");
    ImageRotate(&background1, 90);
    background1Texture = LoadTextureFromImage(background1);
}

void unloadImages()                                                         // Unload images and textures to free memory
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
    UnloadTexture(backgroundTexture);
    UnloadImage(background);
}

void drawMainMenu()                                                         // Draw the main menu with buttons
{
    DrawTexture(background1Texture, 0, 0, WHITE);
    int textWidth = MeasureTextEx(font,"Game of Life", 90,0).x;
    float xPos = (GetScreenWidth() - textWidth) / 2;
    DrawTextEx(font, "Game of Life", { xPos, 100 }, 90, 0, BLACK);
    createButton(300, 300, 200, 50, "Introduction", font, 200, 50);
    createButton(300, 400, 200, 50, "Credits", font, 200, 50);
    createButton(300, 500, 200, 50, "Exit",font, 200, 50);
}

void drawIntroduction()                                                     // Draw the introduction menu with buttons
{
    ClearBackground(GRAY);
    DrawTexture(backgroundTexture, 0, 0, WHITE);
    DrawTexture(conwayTexture,20, 250, WHITE);
    DrawTexture(gameOfLifeExampleTexture, 380, 290, WHITE);
    int introductionTextWidth = MeasureTextEx(font,"Introduction", 50,0).x;
    float xPos = (GetScreenWidth() - introductionTextWidth) / 2;
    int firstLineTextWidth = MeasureTextEx(font, "Conway's Game of Life is a fascinating example of a cellular automaton,", 20, 0).x;
    float firstLineXPos = (GetScreenWidth() - firstLineTextWidth) / 2;
    int secondLineTextWidth = MeasureTextEx(font, "devised by the British mathematician John Horton Conway in 1970.", 20, 0).x;
    float secondLineXPos = (GetScreenWidth() - secondLineTextWidth) / 2;
    int thirdLineTextWidth = MeasureTextEx(font, "Despite its simplicity, this 'zero-player' game exhibits complex and unpredictable behavior.", 20, 0).x;
    float thirdLineXPos = (GetScreenWidth() - thirdLineTextWidth) / 2;

    DrawTextEx(font,"Introduction", {xPos, 20}, 50, 0, WHITE);
    DrawTextEx(font, "Conway's Game of Life is a fascinating example of a cellular automaton,", {firstLineXPos, 100}, 20, 0, WHITE);
    DrawTextEx(font, "devised by the British mathematician John Horton Conway in 1970.", {secondLineXPos, 130}, 20, 0, WHITE);
    DrawTextEx(font, "Despite its simplicity, this 'zero-player' game exhibits complex and unpredictable behavior.", {thirdLineXPos, 160}, 20, 0, WHITE);
    DrawTextEx(font, "John Conway", {20, 580}, 20, 0, WHITE);
    DrawTextEx(font, "Game of Life Example", {380, 580}, 20, 0, WHITE);
    createButton(300, 700, 200, 50, "Continue", font, 200, 50);
    createButton(300, 760, 200, 50, "Skip", font, 200, 50);
    createButton(300, 820, 200, 50, "Back", font, 200, 50);
}

void drawCellTypes()                                                        // Draw the cell types menu with buttons
{
    ClearBackground(WHITE);
    DrawTexture(backgroundTexture, 0, 0, WHITE);
    int cellTypesTextWidth = MeasureTextEx(font, "Cell Types", 50, 0).x;
    float cellTypesXPos = (GetScreenWidth() - cellTypesTextWidth) / 2;
    DrawTextEx(font, "Cell Types", {cellTypesXPos, 20}, 50, 0, WHITE);
    DrawTexture(blockTexture, 70, 140, WHITE);
    DrawTexture(blinkerTexture, 70, 270, WHITE);
    DrawTexture(toadTexture, 70, 400, WHITE);
    DrawTexture(gliderTexture, 70, 530, WHITE);
    createButton(300, 760, 200, 50, "Continue", font, 200, 50);
    createButton(300, 820, 200, 50, "Back", font, 200, 50);

    DrawTextEx(font, "BLOCK:", {20, 90}, 20, 0, WHITE);
    DrawTextEx(font, "A still life pattern that does not change from one generation to the next", {20, 110}, 20, 0, WHITE);
    DrawTextEx(font, "BLINKER:", {20, 220}, 20, 0, WHITE);
    DrawTextEx(font, "A period 2 oscillator that alternates between two states every generation", {20, 240}, 20, 0, WHITE);
    DrawTextEx(font, "TOAD:", {20, 350}, 20, 0, WHITE);
    DrawTextEx(font, "A period 2 oscillator that alternates between two states every generation", {20, 370}, 20, 0, WHITE);
    DrawTextEx(font, "GLIDER:", {20, 480}, 20, 0, WHITE);
    DrawTextEx(font, "A spaceship that moves diagonally across the grid", {20, 500}, 20, 0, WHITE);
    DrawTextEx(font, "OSCILLATOR CELLS:", {20, 650}, 20, 0, WHITE);
    DrawTextEx(font, "These cells form patterns that alternate between two or more states, like blinkers and toads", {20, 670}, 20, 0, WHITE);
    DrawTextEx(font, "SPACESHIP CELLS:", {20, 690}, 20, 0, WHITE);
    DrawTextEx(font, "These cells move across the grid, like gliders", {20, 710}, 20, 0, WHITE);
}

void drawRules()                                                            // Draw the rules menu with buttons
{   
    ClearBackground(WHITE);
    DrawTexture(backgroundTexture, 0, 0, WHITE);
    int rulesTextWidth = MeasureTextEx(font, "Rules", 50, 0).x;
    float rulesXPos = (GetScreenWidth() - rulesTextWidth) / 2;
    DrawTextEx(font, "Rules", {rulesXPos, 20}, 50, 0, WHITE);
    DrawTextEx(font, "LONELINESS:", {280, 140}, 20, 0, WHITE);
    DrawTextEx(font, "A cell with less than 2 adjoining cells dies", {280, 160}, 20, 0, WHITE);
    DrawTextEx(font, "OVERCROWDING:", {280, 270}, 20, 0, WHITE);
    DrawTextEx(font, "A cell with more than 3 adjoining cells dies", {280, 290}, 20, 0, WHITE);
    DrawTextEx(font, "REPRODUCTION:", {280, 400}, 20, 0, WHITE);
    DrawTextEx(font, "An empty cell with 3 adjoining cells becomes alive", {280, 420}, 20, 0, WHITE);
    DrawTextEx(font, "STASIS:", {280, 530}, 20, 0, WHITE);
    DrawTextEx(font, "A cell with exactly 2 adjoining cells survives", {280, 550}, 20, 0, WHITE);

    DrawTexture(lonelinessTexture, 70, 120, WHITE);
    DrawTexture(overcrowdingTexture, 70, 250, WHITE);
    DrawTexture(reproductionTexture, 70, 380, WHITE);
    DrawTexture(stasisTexture, 70, 510, WHITE);
    createButton(300, 700, 200, 50, "Continue", font, 200, 50);
    createButton(300, 760, 200, 50, "Skip", font, 200, 50);
    createButton(300, 820, 200, 50, "Back", font, 200, 50);
}

void drawCredits()                                                          // Draw the credits menu with buttons
{
    ClearBackground(GRAY);
    DrawTexture(background1Texture, 0, 0, WHITE);
    int creditsTextWidth = MeasureTextEx(font, "Credits", 50, 0).x;
    float creditsXPos = (GetScreenWidth() - creditsTextWidth) / 2;
    DrawTextEx(font, "Credits", {creditsXPos, 100}, 50, 0, BLACK);
    DrawTextEx(font, "This game was created by:", {50, 200}, 20,0, BLACK);
    DrawTextEx(font, "Baptiste APPRIOU", {50, 300}, 20, 0, BLACK);
    DrawTextEx(font, "Ali Abakar ISSA", {50, 350}, 20, 0, BLACK);
    DrawTextEx(font, "Oussema FATNASSI", {50, 400}, 20, 0, BLACK);
    createButton(300, 600, 200, 50, "Back", font, 200, 50);
}

void drawCustomMode()                                                       // Draw the custom mode menu with buttons
{
    ClearBackground(backgroundColor);
    createGrid(800, 800, 20);
    createButton(115, 810, 180, 50, "Start Simulation", font, 200, 50);
    createButton(315, 810, 100, 50, "Stop", font, 100, 50);
    createButton(435, 810, 130, 50, "Clear Grid", font, 130, 50);
    createButton(585, 810, 100, 50, "Quit", font, 100, 50);
    DrawTextEx(font, "Generation: ", {500, 930}, 20, 0, WHITE);
    DrawTextEx(font, std::to_string(generationCount).c_str(), {620, 930}, 20, 0, WHITE); // Draw the generation count
    drawFPSSlider();
    createButton(50, 880, 60, 30, "Glider", font, 60, 30);
    createButton(120, 880, 170, 30, "Queen Been Shuttle", font, 170, 30);
    createButton(300, 880, 100, 30, "Glider Gun", font, 100, 30);
    createButton(410, 880, 140, 30, "Pentadecathlon", font, 140, 30);
    createButton(560, 880, 170, 30, "Simkin Glider Gun", font, 170, 30);   
}

void drawRandomMode()                                                           // Draw the random mode menu with buttons
{
    ClearBackground(backgroundColor);
    createGrid(800, 800, 20);
    createButton(50, 820, 100, 50, "Reroll", font, 100, 50);
    createButton(170, 820, 180, 50, "Start Simulation", font, 200, 50);
    createButton(370, 820, 100, 50, "Stop", font, 100, 50);
    createButton(490, 820, 130, 50, "Clear Grid", font, 130, 50);
    createButton(650, 820, 100, 50, "Quit", font, 100, 50);
    DrawTextEx(font, "Generation: ", {500, 930}, 20, 0, WHITE);
    DrawTextEx(font, std::to_string(generationCount).c_str(), {620, 930}, 20, 0, WHITE); // Draw the generation count
    drawFPSSlider();
}

void drawDefaultMode()                                                          // Draw the default mode menu with buttons
{
    ClearBackground(backgroundColor);
    createGrid(800, 800, 20);
    createButton(120, 820, 180, 50, "Start Simulation", font, 180, 50);
    createButton(320, 820, 100, 50, "Stop", font, 100, 50);
    createButton(440, 820, 130, 50, "Clear Grid", font, 130, 50);
    createButton(590, 820, 100, 50, "Quit", font, 100, 50);
    DrawTextEx(font, "Generation: ", {500, 930}, 20, 0, WHITE);
    DrawTextEx(font, std::to_string(generationCount).c_str(), {620, 930}, 20, 0, WHITE); // Draw the generation count
    drawFPSSlider();
}

void drawModeMenu()                                                             // Draw the mode menu with buttons
{
    DrawTexture(background1Texture, 0, 0, WHITE);
    int modeTextWidth = MeasureTextEx(font, "CHOOSE A MODE", 50, 0).x;
    float modexPos = (GetScreenWidth() - modeTextWidth) / 2;
    DrawTextEx(font, "CHOOSE A MODE", {modexPos, 100}, 50, 0, BLACK);
    createButton(300, 200, 200, 50, "Random", font, 200, 50);
    createButton(300, 300, 200, 50, "Default", font, 200, 50);
    createButton(300, 400, 200, 50, "Custom", font, 200, 50);
    createButton(300, 820, 200, 50, "Back", font, 200, 50);
}

void menuInput()                                                                // Check for mouse input in the menus
{
    if (currentMenu == MAIN_MENU)                                                   //MAIN MENU
    {
        if (CheckCollisionPointRec(GetMousePosition(), {300, 300, 200, 50}))        //MAIN MENU: Introduction button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = INTRODUCTION;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 400, 200, 50}))       //MAIN MENU: Credits button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = CREDITS;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 500, 200, 50}))       //MAIN MENU: Exit button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                CloseWindow();
            }
        }
    }
    else if (currentMenu == INTRODUCTION)                                       //INTRODUCTION MENU
    {
        if (CheckCollisionPointRec(GetMousePosition(), {300, 760, 200, 50}))    //INTRODUCTION MENU: skip button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = MODE_MENU;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 820, 200, 50}))   //INTRODUCTION MENU: back button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = MAIN_MENU;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 700, 200, 50}))   //INTRODUCTION MENU: continue button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                drawRules();
                currentMenu = RULES;
            }
        }
    }
    else if (currentMenu == RULES)                                              //RULES MENU
    {
        if (CheckCollisionPointRec(GetMousePosition(), {300, 760, 200, 50}))    //RULES MENU: skip button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = MODE_MENU;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 820, 200, 50}))   //RULES MENU: back button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = INTRODUCTION;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 700, 200, 50}))   //RULES MENU: continue button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                drawCellTypes();
                currentMenu = CELL_TYPES;
            }
        }
    }
    else if (currentMenu == CELL_TYPES)                                         //CELL TYPES MENU
    {
        if (CheckCollisionPointRec(GetMousePosition(), {300, 760, 200, 50}))    //CELL TYPES MENU: continue button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = MODE_MENU;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 820, 200, 50}))   //CELL TYPES MENU: back button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = RULES;
            }
        }
    }
    else if (currentMenu == CREDITS)                                            //CREDITS MENU
    {
        if (CheckCollisionPointRec(GetMousePosition(), {300, 600, 200, 50}))    //CREDITS MENU: back button
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
    if (currentMenu == MODE_MENU)                                               //MODE MENU: choose a mode
    {
        if (CheckCollisionPointRec(GetMousePosition(), {300, 400, 200, 50}))    //MODE MENU: Custom mode button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                drawCustomMode();
                currentMenu = CUSTOM_MODE;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 200, 200, 50}))    //MODE MENU: Random mode button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                drawRandomMode();
                currentMenu = RANDOM_MODE;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 300, 200, 50}))    //MODE MENU: Default mode button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                drawDefaultMode();
                loadGridFromFile("assets/matrices/default.txt");
                currentMenu = DEFAULT_MODE;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 820, 200, 50}))       //MODE MENU: Back button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {   
                drawMainMenu();
                currentMenu = MAIN_MENU;
            }
        }
    }
    else if (currentMenu == CUSTOM_MODE) {                                              //CUSTOM MODE
        customGridSpawn();

        if (CheckCollisionPointRec(GetMousePosition(), {115, 810, 180, 50}))            //CUSTOM MODE: Start simulation button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                isSimulationRunning = true;
            }
        }
        if(isSimulationRunning)                                                         //CUSTOM MODE: Apply Conway's rules if simulation is running
        {
            applyConwayRules();
        }
        
        if (CheckCollisionPointRec(GetMousePosition(), {315, 810, 100, 50}))            //CUSTOM MODE: Stop simulation button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                isSimulationRunning = false;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {435, 810, 130, 50}))       //CUSTOM MODE: Clear grid button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {   
                isSimulationRunning = false;
                clearGridButton();
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {585, 810, 100, 50}))       //CUSTOM MODE: Quit button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {   
                SetTargetFPS(15);
                clearGridButton();
                isSimulationRunning = false;
                drawMainMenu();
                currentMenu = MAIN_MENU;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {50, 880, 60, 30}))       //CUSTOM MODE: load "Glider" matrix
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {   
                isSimulationRunning = false;
                clearGridButton();
                loadGridFromFile("assets/matrices/glider.txt");
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {120, 880, 170, 30}))       //CUSTOM MODE: load "Queen Bee Shuttle" matrix
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {   
                isSimulationRunning = false;
                clearGridButton();
                loadGridFromFile("assets/matrices/queen_bee_shuttle.txt");
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 880, 100, 30}))       //CUSTOM MODE: load "Glider Gun" matrix
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {   
                isSimulationRunning = false;
                clearGridButton();
                loadGridFromFile("assets/matrices/glider_gun.txt");
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {410, 880, 140, 30}))       //CUSTOM MODE: load "Pentadecathlon" matrix
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {   
                isSimulationRunning = false;
                clearGridButton();
                loadGridFromFile("assets/matrices/pentadecathlon.txt");
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {560, 880, 170, 30}))       //CUSTOM MODE: load "Simkin Glider Gun" matrix
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {   
                isSimulationRunning = false;
                clearGridButton();
                loadGridFromFile("assets/matrices/simkin_glider_gun.txt");
            }
        }
        if (CheckCollisionPointRec(GetMousePosition(), {170, 930, 200, 20}))             // FPS slider
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                int mouseX = GetMouseX();

                int fpsIndex = Clamp((mouseX - 170) / (200 / 60), 0, 59);
                int newFPS = fpsValues[fpsIndex];
                SetTargetFPS(newFPS);
            }
        }

        
    }
    else if (currentMenu == RANDOM_MODE)                                        //RANDOM MODE
    {

        if (CheckCollisionPointRec(GetMousePosition(), {50, 820, 100, 50}))    //RANDOM MODE: Reroll button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                isSimulationRunning = false;
                clearGridButton();
                randomSpawn(800, 600, 20);
            }
        }
        if (CheckCollisionPointRec(GetMousePosition(), {170, 820, 180, 50}))    //RANDOM MODE: Start simulation button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                isSimulationRunning = true;
            }
        }
        if(isSimulationRunning)                                                 //RANDOM MODE: Apply Conway's rules if simulation is running
        {
            applyConwayRules();
        }
        
        if (CheckCollisionPointRec(GetMousePosition(), {370, 820, 130, 50}))    //RANDOM MODE: Stop simulation button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                isSimulationRunning = false;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {520, 820, 100, 50}))       //RANDOM MODE: Clear grid button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {   
                isSimulationRunning = false;
                clearGridButton();
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {650, 820, 100, 50}))       //RANDOM MODE: Quit button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {   
                SetTargetFPS(15);
                isSimulationRunning = false;
                clearGridButton();
                drawMainMenu();
                currentMenu = MAIN_MENU;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {170, 930, 200, 20})) // RANDOM MODE: FPS slider
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                int mouseX = GetMouseX();

                int fpsIndex = Clamp((mouseX - 170) / (200 / 60), 0, 59);
                int newFPS = fpsValues[fpsIndex];
                SetTargetFPS(newFPS);
            }
        }
    }
    else if (currentMenu == DEFAULT_MODE)                                                   //DEFAULT MODE
        {

            if (CheckCollisionPointRec(GetMousePosition(), {120, 820, 180, 50}))            //DEFAULT MODE: Start simulation button
            {
                if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                {
                    isSimulationRunning = true;
                }
            }
            if(isSimulationRunning)                                                         //DEFAULT MODE: Apply Conway's rules if simulation is running
            {
                applyConwayRules();
            }
            
            if (CheckCollisionPointRec(GetMousePosition(), {320, 820, 100, 50}))            //DEFAULT MODE: Stop simulation button
            {
                if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                {
                    isSimulationRunning = false;
                }
            }
            else if (CheckCollisionPointRec(GetMousePosition(), {440, 820, 130, 50}))       //DEFAULT MODE: Clear grid button
            {
                if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                {   
                    isSimulationRunning = false;
                    clearGridButton();
                    loadGridFromFile("assets/matrices/default.txt");
                }
            }
            else if (CheckCollisionPointRec(GetMousePosition(), {590, 820, 100, 50}))       //DEFAULT MDOE: Quit button
            {
                if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                {   
                    SetTargetFPS(15);
                    isSimulationRunning = false;
                    clearGridButton();
                    drawMainMenu();
                    currentMenu = MAIN_MENU;
                }
            }
            else if (CheckCollisionPointRec(GetMousePosition(), {170, 930, 200, 20}))       //DEFAULT MODE: FPS slider
            {
                if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                {
                    int mouseX = GetMouseX();

                    int fpsIndex = Clamp((mouseX - 170) / (200 / 60), 0, 59);
                    int newFPS = fpsValues[fpsIndex];
                    SetTargetFPS(newFPS);
                }
            }
        }
}