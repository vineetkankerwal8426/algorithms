// Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

//MEMOIZATION
bool helper(vector<int>&  arr, int sum,int n,vector<vector<int>>&dp){
        if(n==0) return arr[0]==sum;
        if(sum==0) return true;
        if(dp[n][sum]!=-1) return dp[n][sum];
        bool take ;
        if(sum-arr[n]>=0){
            take = helper(arr,sum-arr[n],n-1,dp);
        }
        bool ntake = helper(arr,sum,n-1,dp);
        return dp[n][sum] = take or ntake;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<bool>>dp(arr.size(),vector<bool>(sum+1,-1));
        return helper(arr,sum,arr.size()-1,dp);
    }

//TABULATION
bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<bool>>dp(arr.size(),vector<bool>(sum+1));
        
        //basecase starts {
        dp[0][arr[0]] = true;
        for(int i=0;i<arr.size();i++){
            dp[i][0] = true;
        }
        //basecase ends }
        
        for(int i=1;i<arr.size();i++){
            for(int j =1;j<=sum;j++){
                bool take ;
                if(arr[i]<=j) take = dp[i-1][j-arr[i]];
                bool ntake = dp[i-1][j];
                dp[i][j] = take or ntake;
            }
        }
        return dp[arr.size()-1][sum];
    }