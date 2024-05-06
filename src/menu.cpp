#include <raylib.h>
#include "menu.hpp"

void createButton(int x, int y, int width, int height, const char *text)
{
    DrawRectangle(x, y, width, height, GRAY);
    DrawText(text, x + 10, y + 10, 20, WHITE);
}