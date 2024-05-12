#ifndef GLOBALS_HPP
#define GLOBALS_HPP

enum Menu
{
    MAIN_MENU,
    INTRODUCTION,
    RULES,
    CELL_TYPES,
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
extern int generationCount;
extern Color backgroundColor;


#endif // GLOBALS_HPP