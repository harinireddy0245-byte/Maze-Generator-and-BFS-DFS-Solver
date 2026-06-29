#ifndef DFSSOLVER_H
#define DFSSOLVER_H

#include <vector>

class DFSSolver
{
public:
    static int visitedCount;
    static int pathLength;

    static bool solve(std::vector<std::vector<char>>& maze);
};

#endif