#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

#include <vector>

class MazeGenerator
{
private:
    int rows, cols;
    std::vector<std::vector<char>> maze;

    void carvePath(int r, int c);

public:
    MazeGenerator(int r, int c);

    void generateMaze();
    void displayMaze();

    std::vector<std::vector<char>>& getMaze();
};

#endif