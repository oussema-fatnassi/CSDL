#ifndef GLOBALS_HPP
#define GLOBALS_HPP

enum Menu
{
    MAIN_MENU,
    INTRODUCTION,
    CREDITS
};

extern bool isSimulationRunning;
extern bool gridCells[40][40];
extern Menu currentMenu;

#endif // GLOBALS_HPP