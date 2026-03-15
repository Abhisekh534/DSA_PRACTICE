class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        vector<vector<int>>dp(n, vector<int>(n, 0));

        int mini = INT_MAX;

        for(int i=n-1; i>-1; i--){
            //i ko ulta chalana hai
            //why?? eg, i=0 j=6 k=2, then we need dp[0][2] and dp[2][6], but we don't have real value of dp[2][6] not placeholder 0
            //knowing real value of dp[2][6] in this pass(i=0) is only possible if we have done the pass of i=2 before i=0 
            for(int j=i+2; j<n; j++){
                int mini = INT_MAX;
                for(int k=i+1; k<j; k++){
                    mini = min(mini, values[i]*values[k]*values[j] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = mini;
            }
        }

        return dp[0][n-1];
    }
};