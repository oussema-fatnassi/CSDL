#ifndef GLOBALS_HPP
#define GLOBALS_HPP

enum Menu                                                       // Enum for Menu state
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

extern bool isSimulationRunning;                                // Declaration of Simulation state, to start it and stop it
extern bool gridCells[40][40];                                  // Declaration of grid cells dimensions
extern Menu currentMenu;                                        // Declaration of Menu state    

extern int fpsValues[];                                         // Declaration of FPS values
extern int zoomLevel;                                           // Declaration of Zoom level

extern Font font;                                               // Declaration of Font
extern int generationCount;                                     // Declaration of Generation count
extern Color backgroundColor;                                   // Declaration of Background color

#endif // GLOBALS_HPP