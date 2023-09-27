#include<iostream>
#include<vector>
using namespace std;

void display(vector<vector<bool>>&board){
    for(int i =0;i<board.size();i++){
        for (int j =0;j<board.size();j++){
            if(board[i][j]){
                cout<<"q"<<" ";
            }
            else cout<<"x"<<" ";
        }
        cout<<endl;
    }
}

//check whether the particular row and column of board is safe for queen
bool isSafe(vector<vector<bool>>& board,int row,int col){
    for(int i=0;i<row;i++){//checks above rows of particular column;
        if(board[i][col]){
            return false;
        }
    int maxLeft = min(row,col);//checks the upper left diagonal of board;
    for(int i=1;i<=maxLeft;i++){
        if(board[row-i][col-i]){
            return false;
        }
    }
    int maxRight = board.size()-col-1;//checks the upper right diagonal of board
    for(int i =1;i<=min(maxRight,row);i++){
        if(board[row-i][col+i]){
            return false;
        }
    }
    }
    //if there is no queen cancelling particular row and column than it returns true;
    return true;
}


int queens(vector<vector<bool>>& board,int row){
    if(row == board.size()){
        display(board);
        cout<<endl;
        return 1;
    }
    int count =0;
    for (int col =0;col<board.size();col++){
        if(isSafe(board,row,col)){//checks if this row and column of the board is safe for queen
            board[row][col] = true;
            count += queens(board,row+1);
            board[row][col] = false;//backtracking 
        }
    }
    return count;
}

