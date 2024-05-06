#include <iostream>
#include <cstdlib>
#include <ctime>

const int ROWS = 5;
const int COLS = 5;

// Method to count alive nighbors
int countLiveNeighbors(const int grid[][COLS], int row, int col) {
    int count = 0;
    int rowOffsets[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int colOffsets[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) {
        int newRow = row + rowOffsets[i];
        int newCol = col + colOffsets[i];

        if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS) {
            if (grid[newRow][newCol] == 1) {
                count++;
            }
        }
    }

    return count;
}
void displayGrid(const int grid[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void applyRules(int grid[][COLS]) {
    int nextGrid[ROWS][COLS];

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            int liveNeighbors = countLiveNeighbors(grid, i, j);

            if (grid[i][j] == 0 && liveNeighbors == 3) {
                nextGrid[i][j] = 1; // birth
            } else if (grid[i][j] == 1 && (liveNeighbors == 2 || liveNeighbors == 3)) {
                nextGrid[i][j] = 1; // Stase
            } else {
                nextGrid[i][j] = 0; // dead
            }
        }
    }

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            grid[i][j] = nextGrid[i][j];
        }
    }
}

int main() {
    srand(time(0)); 

    int grid[ROWS][COLS];

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            grid[i][j] = rand() % 2;
        }
    }

    std::cout << "initial grid :" << std::endl;
    displayGrid(grid);

    std::cout << std::endl << "Number of alive nighbors for each cell :" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            int liveNeighbors = countLiveNeighbors(grid, i, j);
            std::cout << liveNeighbors << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "Applying the rules of the game of life" << std::endl;
    applyRules(grid);

    std::cout << std::endl << "grid after one step :" << std::endl;
    displayGrid(grid);

    return 0;
}
