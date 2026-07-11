class Solution {
public:
    int solve(vector<vector<int>>&grid, vector<vector<int>>&dp, int i, int j){
        int n = grid.size();
        int m = grid[0].size();

        if(i>=n || j>=m) return INT_MAX;

        if(i==n-1 && j==m-1) return grid[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] = grid[i][j] + min(solve(grid, dp, i+1, j), solve(grid, dp, i, j+1));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dp(n, vector<int>(m, -1));

        return solve(grid, dp, 0, 0);
    }
};