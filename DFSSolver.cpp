#include "DFSSolver.h"
#include <iostream>
using namespace std;

int DFSSolver::visitedCount = 0;
int DFSSolver::pathLength = 0;

bool dfs(
    vector<vector<char>>& maze,
    vector<vector<bool>>& visited,
    int r,
    int c
)
{
    int rows = maze.size();
    int cols = maze[0].size();

    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return false;

    if (maze[r][c] == '#')
        return false;

    if (visited[r][c])
        return false;

    visited[r][c] = true;
    DFSSolver::visitedCount++;

    if (maze[r][c] == 'E')
        return true;

    // mark tentative path (only for visualization)
    if (maze[r][c] != 'S' && maze[r][c] != 'E')
        maze[r][c] = '*';

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (dfs(maze, visited, nr, nc))
        {
            DFSSolver::pathLength++;
            return true;
        }
    }

    // BACKTRACK (remove wrong path)
    if (maze[r][c] != 'S' && maze[r][c] != 'E')
        maze[r][c] = '.';

    return false;
}

bool DFSSolver::solve(vector<vector<char>>& maze)
{
    visitedCount = 0;
    pathLength = 0;

    int rows = maze.size();
    int cols = maze[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    int sr = -1, sc = -1;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (maze[i][j] == 'S')
            {
                sr = i;
                sc = j;
            }
        }
    }

    return dfs(maze, visited, sr, sc);
}