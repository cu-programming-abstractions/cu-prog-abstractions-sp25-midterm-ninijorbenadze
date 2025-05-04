#include "maze_solver.h"
#include <stack>
using namespace std;

bool MazeSolver::dfs(Maze& maze, int r, int c, vector<vector<bool>>& visited) {
    /* TODO: Implement recursive DFS with backtracking.*/
    if(!maze.inBounds(r, c) || maze.isWall(r, c) || visited[r][c]) {
        return false;
    }//Goal check
    if(r == maze.finish.row && c == maze.finish.col) {
        maze.path.push_back({r, c});
        return true;
    }

    //mark the cell as visited
    visited[r][c] = true;
        //direction exploring
    if(dfs(maze, r, c - 1, visited) || dfs(maze, r - 1, c, visited) || dfs(maze, r, c + 1, visited) || dfs(maze, r + 1, c, visited)) {
        //if any leads to successful direction add to the path
        maze.path.push_back({r, c});
        return true;
    }


    return false;
}

bool MazeSolver::solveDFS(Maze& maze) {
    // Clear any existing path
    maze.path.clear();
    
    // Create visited matrix
    vector<vector<bool>> visited(maze.grid.size(), 
                               vector<bool>(maze.grid[0].size(), false));
    
    // Start DFS from the start position
    bool found = dfs(maze, maze.start.row, maze.start.col, visited);
    
    // If path found, add the start position to the path
    if (found) {
        maze.path.push_back(maze.start);
    }
    
    return found;
}
