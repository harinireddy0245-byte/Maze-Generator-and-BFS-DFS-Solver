#include "BFSSolver.h"
#include <queue>
#include <iostream>

using namespace std;
int BFSSolver::visitedCount=0;
int BFSSolver::pathLength=0;
bool BFSSolver::solve(vector<vector<char>>& maze)
{
    visitedCount=0;
pathLength=0;
    int rows=maze.size();
    int cols=maze[0].size();

    queue<pair<int,int>> q;

    vector<vector<bool>> visited(
        rows,
        vector<bool>(cols,false)
    );

    vector<vector<pair<int,int>>> parent(
        rows,
        vector<pair<int,int>>(cols,{-1,-1})
    );

    int sr=-1,sc=-1;
    int er=-1,ec=-1;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(maze[i][j]=='S')
            {
                sr=i;
                sc=j;
            }

            if(maze[i][j]=='E')
            {
                er=i;
                ec=j;
            }
        }
    }

    q.push({sr,sc});
    visited[sr][sc]=true;
    visitedCount=1;

    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};

    while(!q.empty())
    {
        auto current=q.front();
        q.pop();

        int r=current.first;
        int c=current.second;

        if(r==er && c==ec)
        {
            break;
        }

        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nr<rows &&
               nc>=0 && nc<cols &&
               !visited[nr][nc] &&
               maze[nr][nc]!='#')
            {
                visited[nr][nc]=true;
                visitedCount++;
                parent[nr][nc]={r,c};

                q.push({nr,nc});
            }
        }
    }

    if(!visited[er][ec])
        return false;

    int r=er;
    int c=ec;

    while(!(r==sr && c==sc))
    {
        pathLength++;
        if(maze[r][c]!='E')
            maze[r][c]='*';

        auto p=parent[r][c];

        r=p.first;
        c=p.second;
    }

    return true;
}