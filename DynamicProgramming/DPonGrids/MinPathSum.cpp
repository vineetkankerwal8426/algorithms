// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
// which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.


//MEMOIZATION
int helper(vector<vector<int>>& grid,int m,int n ,vector<vector<int>>& dp){
        if(m==0 and n==0) return grid[0][0];
        if(dp[m][n]!=-1) return dp[m][n];
        int left = INT_MAX;
        int up =INT_MAX;
        if(n>0){
            left = grid[m][n]+ helper(grid,m,n-1,dp);
        }
        if(m>0) {
            up =grid[m][n]+ helper(grid, m-1,n,dp);
        }
        return dp[m][n] = min(left,up);
    }

int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return helper(grid,grid.size()-1,grid[0].size()-1,dp);
    }



//TABULATION

int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size()));

        //basecase starts {
        dp[0][0] = grid[0][0];
        
        for(int i=1;i<grid[0].size();i++){
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }
        for(int i=1;i<grid.size();i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        //basecase ends }

        for(int i =1;i<grid.size();i++){
            for(int j =1;j<grid[0].size();j++){
                if(i==0) dp[i][j] = grid[i][j] + dp[i][j-1];
                if(j==0) dp[i][j] = grid[i][j] + dp[i-1][j];
                else
                dp[i][j]= grid[i][j]+ min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];    
    }

//more optimized TABULATION, make basecases in single loop
int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size()));
        // return helper(grid,grid.size()-1,grid[0].size()-1,dp);

        dp[0][0] = grid[0][0];

        for(int i =0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                if(i ==0 and j==0) continue;   //base case 
                if(i==0){  //base case
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                    continue;
                } 
                if(j==0){ //basecase 
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                    continue;
                }
            
                dp[i][j]= grid[i][j]+ min(dp[i-1][j],dp[i][j-1]); 
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];    
    }