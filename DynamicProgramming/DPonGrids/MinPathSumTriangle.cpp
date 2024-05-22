// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, 
// if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

//    2
//   3 4
//  6 5 7
// 4 1 8 3

//MEMOIZATION
int helper(vector<vector<int>>& triangle,int m,int n,vector<vector<int>>& dp){
        if(m == triangle.size()-1) return triangle[m][n];
        if(dp[m][n]!=-1) return dp[m][n];

        int down = triangle[m][n] + helper(triangle,m+1,n,dp);
        int diagonal = triangle[m][n] + helper(triangle, m+1, n+1,dp);
        return dp[m][n] = min(down,diagonal);
}

int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-1));
        return helper(triangle,0,0,dp);
}



//TABULATION
int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size()));
       
        int m = triangle.size()-1;
        //basecase starts {
        for(int i =0;i<triangle.size();i++){
            dp[m][i] = triangle[m][i];
        }
        //basecase ends } 
        for(int i= m-1;i>=0;i--){
            for(int j =0;j<triangle[i].size();j++){
                dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }