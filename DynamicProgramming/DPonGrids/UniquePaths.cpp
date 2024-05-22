// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
//  The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
//  The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

//MEMOIZATION
int helper(int m,int n,vector<vector<int>>& dp){  //we will start from m-1,n-1 and go to 0;
        if(n==0 or m ==0) return 1;
        if(dp[m][n] != -1) return dp[m][n]; 
        int up = helper(m-1,n,dp);
        int left = helper(m, n-1,dp);
        return dp[m][n] = left + up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return helper(m-1,n-1,dp);
    }


//TABULATION

int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n));

        //basecase starts{
        for(int i =0;i<n;i++){  
            dp[0][i] = 1;
        }
        for(int i =0;i<m;i++){
            dp[i][0] = 1;
        }
        //basecase ends}
        
        for(int i =1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]= dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
}

