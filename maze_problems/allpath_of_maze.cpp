#include<iostream>
#include<vector>
using namespace std;

//will print all the path if you allowed (left right down up) in the maze;

void allpath(string p,vector<vector<bool>> &maze, int r , int c){  // maze bool vector will ensure that you have visited last block of maze and avoid infinte recursion;
    if(r == maze.size()-1 && c == maze[0].size()-1){
        cout<<p<<endl;
        return;
    }

    if(maze[r][c]== false){
        return;
    }
    maze[r][c] = 0;  // make visited block false, so that recursive function will not go again to that block
    if(r<maze.size()-1){
        allpath(p+'d',maze,r+1,c);
    }
    if(c<maze[0].size()-1){
        allpath(p+'r',maze,r,c+1);
    }
    if(r>0){
        allpath(p+'u',maze,r-1,c);
    }
    if(c>0){
        allpath(p+'l',maze,r,c-1);
    }
    maze[r][c] = 1; // backtracking for future function calls.

}
