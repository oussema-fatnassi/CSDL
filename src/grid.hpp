#ifndef GRID_H
#define GRID_H

void saveGridToFile();
void loadGridFromFile();
void createGrid(int screenWidth, int screenHeight, int cellSize);
void randomSpawn(int screenWidth, int screenHeight, int cellSize);
int countLiveNeighbors(int i, int j);
void applyConwayRules();
void customGridSpawn();

#endif  