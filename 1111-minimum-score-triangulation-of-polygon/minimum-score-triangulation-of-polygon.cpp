class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        vector<vector<int>>dp(n, vector<int>(n, 0));

        int mini = INT_MAX;

        for(int i=n-1; i>-1; i--){
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