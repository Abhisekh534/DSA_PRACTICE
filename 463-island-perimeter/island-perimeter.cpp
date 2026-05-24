class Solution {
public:
    int dfs(vector<vector<int>>&grid, int i, int j, vector<vector<int>>&visited){
        int n = grid.size();
        int m = grid[0].size();

        if(i<0 || i==n || j<0 || j==m || grid[i][j]==0) return 1;

        if(visited[i][j]) return 0;

        visited[i][j] = true;
        
        int left = dfs(grid, i, j-1, visited);
        int right = dfs(grid, i, j+1, visited);
        int top = dfs(grid, i-1, j, visited);
        int bottom = dfs(grid, i+1, j, visited);

        return left + right + top + bottom;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n, vector<int>(m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1) return dfs(grid, i, j, visited);
            }
        }
        return 0; 
    }
};