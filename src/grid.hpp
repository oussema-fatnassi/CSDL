#ifndef GRID_H
#define GRID_H

void createGrid(int screenWidth, int screenHeight, int cellSize);
void randomSpawn(int screenWidth, int screenHeight, int cellSize);
int countLiveNeighbors(int i, int j);
void applyConwayRules();
void customGridSpawn();
void saveGridToFile();
void loadGridFromFile();

#endif  