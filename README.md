Project Overview:
The Maze Generator and Solver is a C++ application developed to demonstrate the concepts of maze generation and pathfinding algorithms. The project combines recursive maze generation with two widely used graph traversal algorithms, Breadth-First Search (BFS) and Depth-First Search (DFS), to create and solve random mazes. It also evaluates the generated maze by assigning a difficulty level based on several performance metrics.
The primary objective of this project is to help users understand how search algorithms operate in different scenarios while providing a simple and interactive console-based interface. The application allows users to generate random mazes of custom dimensions, visualize them, solve them using BFS or DFS, and compare the results based on the number of visited cells and path length.
Features:
The project offers the following features:
 1.Random maze generation using recursive backtracking.
 2.User-defined maze dimensions.
 3.Automatic placement of the start (S) and end (E) points.
 4.Maze solving using Breadth-First Search (BFS).
 5.Maze solving using Depth-First Search (DFS).
 6.Visualization of the discovered solution path.
 7.Display of the number of visited cells.
 8.Calculation of the shortest or explored path length.
 9.Automatic maze difficulty rating as Easy, Medium, or Hard.
 10.Interactive menu-driven console application.
 Technologies Used:
   1.Programming Language: C++
   2.Compiler: GNU G++ Compiler
   3.IDE: Visual Studio Code
   4.Version Control: Git and GitHub
   5.Libraries Used:
       <iostream>
       <vector>
       <queue>
       <algorithm>
       <random>
       <ctime>
       <string>
Project Description:
The project begins by asking the user to enter the number of rows and columns for the maze. Based on the provided dimensions, the program generates a random maze consisting of walls and open paths. The recursive backtracking technique is used to ensure that the maze has a valid path from the starting point to the destination.
After generating the maze, the user is presented with an interactive menu where different operations can be performed. The maze can be displayed at any time, and the user can choose either the BFS or DFS algorithm to solve it.
The BFS algorithm explores the maze level by level and always guarantees the shortest path if one exists. It records every visited cell and reconstructs the shortest route once the destination is reached.
The DFS algorithm follows one path as deeply as possible before backtracking whenever it encounters a dead end. Although DFS does not always produce the shortest path, it is simple, efficient, and demonstrates recursive traversal effectively.
After solving the maze, the application displays the solved maze with the discovered path highlighted. It also reports the total number of visited cells and the path length. These values are then used by the Difficulty Rater module to estimate the overall complexity of the generated maze.
Working Principle:
The maze is generated first using recursive backtracking, which creates interconnected pathways while maintaining randomness. The generated maze contains a predefined starting position (S) and an ending position (E).
When BFS is selected, the algorithm explores neighboring cells level by level until it reaches the destination. It stores parent information to reconstruct the shortest route.
When DFS is selected, the algorithm recursively traverses the maze until the destination is found or all possible paths have been explored.
Finally, the program analyzes the maze based on:
Maze dimensions
Number of visited cells
Path length
These values are used to classify the maze difficulty as Easy, Medium, or Hard.
Applications:
This project has practical applications in several areas, including:
 1.Algorithm visualization and education
 2.Artificial Intelligence pathfinding
 3.Robotics navigation
 4.Game development
 5.Graph theory demonstrations
 6.Data structures and algorithm learning
 Conclusion:
The Maze Generator and Solver successfully demonstrates the practical implementation of maze generation and graph traversal algorithms in C++. By integrating BFS, DFS, and a difficulty evaluation mechanism into a single application, the project provides an effective platform for learning fundamental concepts in data structures, algorithms, and problem-solving. The modular design, interactive interface, and clear visualization of the solution paths make the application suitable for academic projects, programming practice, and algorithm demonstrations. Future enhancements may include graphical visualization, additional search algorithms such as A* and Dijkstra's Algorithm, and support for exporting generated mazes, making the application more versatile and feature-rich.
