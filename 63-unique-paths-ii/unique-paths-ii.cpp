class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp, int i, int j){
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(i>=n || j>=m || obstacleGrid[i][j]==1) return 0;
        if(i==n-1 && j==m-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int down = solve(obstacleGrid, dp, i+1, j);

        int right = solve(obstacleGrid, dp, i, j+1);
        
        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(obstacleGrid, dp, 0, 0);
    }
};