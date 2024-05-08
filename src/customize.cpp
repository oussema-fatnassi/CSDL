#include <iostream>
#include <raylib.h>
#include "globals.hpp"


// Define a custom Clamp function
int Clamp(int value, int min, int max)
{
    return (value < min) ? min : (value > max) ? max : value;
}

void drawFPSSlider()
{
    float sliderWidth = 200;
    float sliderHeight = 20;
    float sliderX = 70;
    float sliderY = 950;
    static int fpsIndex = 0; // Make fpsIndex static to retain its value between frames

    // Update fpsIndex based on mouse position when clicking and dragging
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {sliderX, sliderY, sliderWidth, sliderHeight}))
    {
        int mouseX = GetMouseX();
        fpsIndex = (mouseX - sliderX) / (sliderWidth / 5);
        fpsIndex = Clamp(fpsIndex, 0, 5); // Clamp fpsIndex to the valid range
    }

    DrawRectangle(sliderX, sliderY, sliderWidth, sliderHeight, WHITE);
    DrawRectangle(sliderX + (fpsIndex * (sliderWidth / 5)), sliderY, 10, sliderHeight, BLACK);
}