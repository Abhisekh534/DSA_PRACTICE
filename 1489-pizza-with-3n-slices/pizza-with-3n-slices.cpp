class Solution {
public:
    int solve(int i, int j, vector<int>&slices, int r, vector<vector<int>>&dp){
        if(r==0 || i>j) return 0;

        if(dp[i][r]!=-1) return dp[i][r];

        int take = slices[i] + solve(i+2, j, slices, r-1, dp);
        int skip = solve(i+1, j, slices, r, dp);

        return dp[i][r] = max(take, skip);
    }
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();

        vector<vector<int>>dp1(n, vector<int>(n/3 + 1, -1));
        vector<vector<int>>dp2(n, vector<int>(n/3 + 1, -1));

        int take = solve(0, n-2, slices, n/3, dp1);
        int skip = solve(1, n-1, slices, n/3, dp2);

        return max(take, skip);
    }
};