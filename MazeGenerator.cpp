#include "MazeGenerator.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

static mt19937 rng(time(0));

MazeGenerator::MazeGenerator(int r,int c)
{
    rows=r;
    cols=c;

    maze.resize(rows,vector<char>(cols,'#'));
}

void MazeGenerator::carvePath(int r,int c)
{
    maze[r][c]='.';

    vector<pair<int,int>> dirs =
    {
        {-2,0},
        {2,0},
        {0,-2},
        {0,2}
    };

    shuffle(dirs.begin(), dirs.end(), rng);

    for(auto dir : dirs)
    {
        int nr = r + dir.first;
        int nc = c + dir.second;

        if(nr>0 && nr<rows-1 &&
           nc>0 && nc<cols-1 &&
           maze[nr][nc]=='#')
        {
            maze[r + dir.first/2][c + dir.second/2]='.';

            carvePath(nr,nc);
        }
    }
}



    void MazeGenerator::generateMaze()
{
    maze.assign(rows, vector<char>(cols,'#'));

    carvePath(1,1);
    for(int i=1;i<rows-1;i++)
{
    for(int j=1;j<cols-1;j++)
    {
        if(maze[i][j]=='#')
        {
            if(rand()%100 < 15)
            {
                maze[i][j]='.';
            }
        }
    }
}

    maze[1][1]='S';

    // find reachable place for E
    for(int i=rows-2;i>=1;i--)
    {
        for(int j=cols-2;j>=1;j--)
        {
            if(maze[i][j]=='.')
            {
                maze[i][j]='E';
                return;
            }
        }
    }
}


void MazeGenerator::displayMaze()
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<maze[i][j]<<" ";
        }

        cout<<endl;
    }
}

vector<vector<char>>& MazeGenerator::getMaze()
{
    return maze;
}