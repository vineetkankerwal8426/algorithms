// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

//MEOMOIZATION

int helper(string & t1, string & t2,int i ,int j,vector<vector<int>>&dp){
        if(i==0 or j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(t1[i-1]==t2[j-1]) return dp[i][j]=  1+helper(t1,t2,i-1,j-1,dp);
        return dp[i][j] = max(helper(t1,t2,i-1,j,dp),helper(t1,t2,i,j-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1));
        return helper(text1,text2,text1.size(),text2.size(),dp);
    }


//TABULATION
int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1));

        //basecase starts {}
        for(int i=0;i<=text1.size();i++){
            dp[i][0] = 0;
        }
        for(int i =0;i<=text2.size();i++){
            dp[0][i] = 0;
        }
        //basecase ends }

        for(int i =1;i<=text1.size();i++){
            for(int j =1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    // break;
                } 
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);             
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
