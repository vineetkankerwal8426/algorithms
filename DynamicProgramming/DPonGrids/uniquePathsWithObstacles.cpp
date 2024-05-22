// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]).
//  The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
//  The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. 
// A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.


//MEMOIZATION
int helper(vector<vector<int>>& obgrid,int m,int n,vector<vector<int>>& dp){
        if(dp[m][n] != -1) return dp[m][n];
        if(obgrid[m][n]==1) return 0;  //if obstacle present return 0 because there is no way to go from that path;
        if(m == 0 and n ==0) return 1;

        int up =0;
        int left =0;
        if(m>0)
         up +=helper(obgrid,m-1,n,dp);
        if(n>0)
         left += helper(obgrid,m,n-1,dp);
        return dp[m][n] = up+left;
    }

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<long long int >> dp(obstacleGrid.size(),vector<long long int>(obstacleGrid[0].size(),-1));
         return helper(obstacleGrid,obstacleGrid.size()-1,obstacleGrid[0].size()-1,dp);
    }



//TABULATION
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<long long int >> dp(obstacleGrid.size(),vector<long long int>(obstacleGrid[0].size()));

        //basecase starts{}
        bool obstacle = false;
        for(int i =0;i<obstacleGrid.size();i++){
            if(obstacleGrid[i][0] != 1 and !obstacle){
                dp[i][0] = 1;
            }else obstacle = true;
        }
        
        obstacle = false;
        for(int i =0;i<obstacleGrid[0].size();i++){
            if(obstacleGrid[0][i] != 1 and !obstacle){
                dp[0][i] = 1;
            }else obstacle = true;
        }
        //basecase ends }

        for(int i =1;i<obstacleGrid.size();i++){
            for(int j =1;j<obstacleGrid[i].size();j++){
                if(obstacleGrid[i][j] ==1){
                    dp[i][j] = 0;
                    continue;
                } 
                long long  up =0;  //long long is because there is any intermiate answer which is overflowing 
                long long  left =0;
               
                up = up+ dp[i-1][j];
                left = left+ dp[i][j-1];

                dp[i][j] = (up+left);
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
}