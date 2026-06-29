#ifndef DIFFICULTYRATER_H
#define DIFFICULTYRATER_H

#include <string>

class DifficultyRater
{
public:
    static std::string rateDifficulty(
        int pathLength,
        int visitedCells,
        int rows,
        int cols
    );
};

#endif