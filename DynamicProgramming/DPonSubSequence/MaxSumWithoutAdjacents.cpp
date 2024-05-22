// Given an array Arr of size N containing positive integers. 
// Find the maximum sum of a any possible subsequence such that no two numbers in the subsequence should be adjacent in Arr.


//MEMOIZATION
int helper(int * arr,int n,vector<int> & dp){
	  
	    if(n ==0) return arr[0];
	    if(dp[n]!= -1) return dp[n];
	    int pick = arr[n];
	    if(n-2>=0){    
	        pick += helper(arr,n-2,dp);
	    }
	    int npick = 0+ helper(arr,n-1,dp);
	   // return max(npick,pick);
	    return (dp[n] = max(npick,pick));
	}

int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n,-1);
	   return helper(arr,n-1,dp);
}

//TABULATION

	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n,0);
	   
	   dp[0] = arr[0];   //base case 

	   for(int i =1;i<n;i++){
	       int pick = arr[i];
	       if(i-2>=0) pick += dp[i-2];
	       int npick = 0+ dp[i-1];
	       dp[i] = max(pick,npick);
	   }
	   return dp[n-1];
	    
	}