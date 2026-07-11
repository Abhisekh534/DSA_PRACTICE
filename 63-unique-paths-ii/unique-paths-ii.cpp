class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>&memo, int i, int j){
        int n = grid.size();
        int m = grid[0].size();

        if(i>=n || j>=m || grid[i][j]==1) return 0;
        
        if(i==n-1 && j==m-1) return 1;

        if(memo[i][j]!=-1) return memo[i][j];

        int right = dfs(grid, memo, i, j+1);
        int down = dfs(grid, memo, i+1, j);

        return memo[i][j] = right + down;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[n-1][m-1]==1) return 0;

        vector<vector<int>>memo(n, vector<int>(m, -1));

        return dfs(obstacleGrid, memo, 0, 0);
    }
};