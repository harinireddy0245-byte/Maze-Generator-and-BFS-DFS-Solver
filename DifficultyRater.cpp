#include "DifficultyRater.h"

using namespace std;

string DifficultyRater::rateDifficulty(
    int pathLength,
    int visitedCells,
    int rows,
    int cols
)
{
    int score = 0;

    if(rows * cols > 400)
        score += 2;
    else if(rows * cols > 150)
        score += 1;

    if(pathLength > 50)
        score += 2;
    else if(pathLength > 20)
        score += 1;

    if(visitedCells > 100)
        score += 2;
    else if(visitedCells > 50)
        score += 1;

    if(score >= 5)
        return "HARD";
    else if(score >= 3)
        return "MEDIUM";
    else
        return "EASY";
}