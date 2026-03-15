class Solution {
public:
    int solve(vector<int>&values, vector<vector<int>>&dp, int i, int j){
        if(j-i==1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int mini = INT_MAX;
        for(int x=i+1; x<j; x++){
            int ans = values[i]*values[x]*values[j] + solve(values, dp, i, x) + solve(values, dp, x, j);
            mini = min(mini, ans);
        }

        return dp[i][j] = mini;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        vector<vector<int>>dp(n, vector<int>(n, -1));

        return solve(values, dp, 0, n-1);
    }
};