#include <iostream>
#include "MazeGenerator.h"
#include "BFSSolver.h"
#include "DFSSolver.h"
#include "difficultyrater.h"

using namespace std;

int main()
{
    int rows, cols;

    cout << "Enter rows: ";
    cin >> rows;

    cout << "Enter cols: ";
    cin >> cols;

    MazeGenerator maze(rows, cols);
    maze.generateMaze();

    int choice;

    do
    {
        cout << "\n========== MAZE SOLVER ==========\n";
        cout << "1. Show Maze\n";
        cout << "2. BFS Solve\n";
        cout << "3. DFS Solve\n";
        cout << "4. Generate New Maze\n";
        cout << "5. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                maze.displayMaze();
                break;
            }

            case 2:
            {
                auto bfsMaze = maze.getMaze();

                bool found = BFSSolver::solve(bfsMaze);

                if(found)
                    cout << "\nBFS PATH FOUND!\n";
                else
                    cout << "\nNO PATH FOUND!\n";

                for(auto row : bfsMaze)
                {
                    for(auto cell : row)
                        cout << cell << " ";

                    cout << endl;
                }

                cout << "\nVisited Cells: "
                     << BFSSolver::visitedCount;

                cout << "\nPath Length: "
                     << BFSSolver::pathLength;

                cout << "\nMaze Difficulty: "
                     << DifficultyRater::rateDifficulty(
                            BFSSolver::pathLength,
                            BFSSolver::visitedCount,
                            rows,
                            cols
                        ) << endl;

                break;
            }

            case 3:
            {
                auto dfsMaze = maze.getMaze();

                bool found = DFSSolver::solve(dfsMaze);

                if(found)
                    cout << "\nDFS PATH FOUND!\n";
                else
                    cout << "\nNO PATH FOUND!\n";

                for(auto row : dfsMaze)
                {
                    for(auto cell : row)
                        cout << cell << " ";

                    cout << endl;
                }

                cout << "\nVisited Cells: "
                     << DFSSolver::visitedCount;

                cout << "\nPath Length: "
                     << DFSSolver::pathLength;

                cout << "\nMaze Difficulty: "
                     << DifficultyRater::rateDifficulty(
                            DFSSolver::pathLength,
                            DFSSolver::visitedCount,
                            rows,
                            cols
                        ) << endl;

                break;
            }

            case 4:
            {
                cout << "Enter new rows: ";
                cin >> rows;

                cout << "Enter new cols: ";
                cin >> cols;

                maze = MazeGenerator(rows, cols);
                maze.generateMaze();

                cout << "\nNEW MAZE GENERATED!\n";
                break;
            }

            case 5:
            {
                cout << "\nExiting Program...\n";
                break;
            }

            default:
            {
                cout << "\nInvalid Choice!\n";
            }
        }

    } while(choice != 5);

    return 0;
}