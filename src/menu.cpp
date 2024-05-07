#include <iostream>
#include <raylib.h>
#include "menu.hpp"
#include "buttons.hpp"
#include "globals.hpp"
#include "grid.hpp"

using namespace std;


void drawMainMenu()
{
    ClearBackground(GRAY);
    DrawText("Game of Life", 350, 100, 50, BLACK);
    createButton(300, 300, 200, 50, "Introduction");
    createButton(300, 400, 200, 50, "Credits");
    createButton(300, 500, 200, 50, "Exit");
}

void drawIntroduction()
{
    ClearBackground(GRAY);
    DrawText("Introduction", 350, 100, 50, BLACK);
    DrawText("The Game of Life is a cellular automaton devised by the British mathematician John Horton Conway in 1970.", 50, 200, 15, WHITE);
    DrawText("The game is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.", 50, 250, 15, WHITE);
    DrawText("One interacts with the Game of Life by creating an initial configuration and observing how it evolves.", 50, 300, 15, WHITE);
    createButton(300, 600, 200, 50, "Skip");
    createButton(300, 700, 200, 50, "Back");
}

void drawCredits()
{
    ClearBackground(GRAY);
    DrawText("Credits", 350, 100, 50, BLACK);
    DrawText("This game was created by the following people:", 50, 200, 20, WHITE);
    DrawText("Baptiste APPRIOU", 50, 250, 20, BLACK);
    DrawText("Ali Abakar ISSA", 50, 300, 20, BLACK);
    DrawText("Oussema FATNASSI", 50, 350, 20, BLACK);
    createButton(300, 600, 200, 50, "Back");
}

void drawCustomMode()
{
    ClearBackground(GRAY);
    createGrid(800, 800, 20);
    createButton(50, 880, 180, 50, "Start Simulation");
    createButton(250, 880, 100, 50, "Stop");
    createButton(370, 880, 130, 50, "Clear Grid");
    createButton(520, 880, 100, 50, "Quit");

}

void drawModeMenu()
{
    createButton(350, 200, 100, 50, "Random");
    createButton(350, 300, 100, 50, "Default");
    createButton(350, 400, 100, 50, "Custom");
    createButton(350, 550, 100, 50, "Back");
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
        if (CheckCollisionPointRec(GetMousePosition(), {300, 600, 200, 50}))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = MODE_MENU;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 700, 200, 50}))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                currentMenu = MAIN_MENU;
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
        else if (CheckCollisionPointRec(GetMousePosition(), {520, 880, 100, 50}))       //Quit button
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {   
                drawMainMenu();
                currentMenu = MAIN_MENU;
            }
        }
    }
}