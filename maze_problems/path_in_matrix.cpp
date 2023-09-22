#include<iostream>
#include<vector>
using namespace std;

//print the matrix with path of the maze;

void printPathMatrix(string p,vector<vector<bool>> &maze,vector<vector<int>>&path, int r , int c,int step){ //r ,c initially will be zero;
    if(r == maze.size()-1 && c == maze[0].size()-1){
        path[r][c] = step;
        for(auto i: path){
            for(int j : i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<p<<endl;
        return;
    }

    if(maze[r][c]== false){
        return;
    }
    maze[r][c] = 0;
    path[r][c] = step;
    if(r<maze.size()-1){
        printPathMatrix(p+'d',maze,path,r+1,c,step+1);
    }
    if(c<maze[0].size()-1){
        printPathMatrix(p+'r',maze,path,r,c+1,step+1);
    }
    if(r>0){
        printPathMatrix(p+'u',maze,path,r-1,c,step+1);
    }
    if(c>0){
        printPathMatrix(p+'l',maze,path,r,c-1,step+1);
    }
    maze[r][c] = 1;  //backtracking
    path[r][c] =0;  // backtracking
}

