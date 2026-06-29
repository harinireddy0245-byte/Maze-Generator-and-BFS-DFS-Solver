#ifndef BFSSOLVER_H
#define BFSSOLVER_H

#include <vector>

class BFSSolver
{
public:
    static int visitedCount;
    static int pathLength;

    static bool solve(std::vector<std::vector<char>>& maze);
};

#endif