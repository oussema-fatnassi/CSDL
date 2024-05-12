#include <iostream>
#include <raylib.h>
#include "globals.hpp"

int Clamp(int value, int min, int max)
{
    return (value < min) ? min : (value > max) ? max : value;
}

void drawFPSSlider()
{
    float sliderWidth = 200;
    float sliderHeight = 20;
    float sliderX = 170;
    float sliderY = 930;
    static int fpsIndex = 14; 

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {sliderX, sliderY, sliderWidth, sliderHeight}))
    {
        int mouseX = GetMouseX();
        fpsIndex = (mouseX - sliderX) / (sliderWidth / 60); 
        fpsIndex = Clamp(fpsIndex, 0, 59); 
    }

    DrawRectangle(sliderX, sliderY, sliderWidth, sliderHeight, WHITE);
    DrawRectangle(sliderX + (fpsIndex * (sliderWidth / 60)), sliderY, 10, sliderHeight, LIGHTGRAY);

    DrawTextEx(font,TextFormat("FPS: %d", fpsValues[fpsIndex]), {sliderX + sliderWidth + 10, sliderY}, 20, 0, WHITE);
}

void drawZoomSlider()
{
    float sliderWidth = 200;
    float sliderHeight = 20;
    float sliderX = 400;
    float sliderY = 950;

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {sliderX, sliderY, sliderWidth, sliderHeight}))
    {
        int mouseX = GetMouseX();
        zoomLevel = (mouseX - sliderX) / (sliderWidth / 10); 
        zoomLevel = Clamp(zoomLevel, 1, 5); 
    }

    DrawRectangle(sliderX, sliderY, sliderWidth, sliderHeight, WHITE);
    DrawRectangle(sliderX + (zoomLevel * (sliderWidth / 5)), sliderY, 10, sliderHeight, BLACK);

    DrawText(TextFormat("Zoom: %d", zoomLevel), sliderX + sliderWidth + 10, sliderY, 20, BLACK);
}