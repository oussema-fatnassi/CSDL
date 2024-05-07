#include <iostream>
#include <raylib.h>
#include "menu.hpp"
#include "buttons.hpp"
#include "globals.hpp"

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
    createButton(300, 600, 200, 50, "Back");
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

void drawMenu()
{
    switch (currentMenu)
    {
    case MAIN_MENU:
        drawMainMenu();
        break;
    case INTRODUCTION:
        drawIntroduction();
        break;
    case CREDITS:
        drawCredits();
        break;
    default:
        break;
    }
}

void menuInput()
{
    if (currentMenu == MAIN_MENU)
    {
        if (CheckCollisionPointRec(GetMousePosition(), {300, 300, 200, 50}))
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                currentMenu = INTRODUCTION;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 400, 200, 50}))
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                currentMenu = CREDITS;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), {300, 500, 200, 50}))
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                CloseWindow();
            }
        }
    }
    else
    {
        if (CheckCollisionPointRec(GetMousePosition(), {300, 600, 200, 50}))
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                currentMenu = MAIN_MENU;
            }
        }
    }
}