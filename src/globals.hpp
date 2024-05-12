#ifndef GLOBALS_HPP
#define GLOBALS_HPP

enum Menu
{
    MAIN_MENU,
    INTRODUCTION,
    CREDITS,
    CUSTOM_MODE,
    RANDOM_MODE,
    DEFAULT_MODE,
    MODE_MENU
};

extern bool isSimulationRunning;
extern bool gridCells[40][40];
extern Menu currentMenu;

extern int fpsValues[];
extern int zoomLevel;

extern Font font;
extern Image icon;

#endif // GLOBALS_HPP