class Solution {
public:
    int solve(vector<int>&v, vector<vector<int>>&dp, int i, int j){
        if(j-i==1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int mini = INT_MAX;
        for(int x=i+1; x<j; x++){
            mini = min(mini, v[i]*v[x]*v[j] + solve(v, dp, i, x) + solve(v, dp, x, j));
        }

        return dp[i][j] = mini;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        vector<vector<int>>dp(n, vector<int>(n, -1));

        return solve(values, dp, 0, n-1);
    }
};