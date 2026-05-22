class Solution {
public:
    void dfs(vector<vector<char>>&grid, int i, int j, vector<vector<int>>&visited){
        int n = grid.size();
        int m = grid[0].size();

        if(i<0 || i==n || j<0 || j==m || grid[i][j]=='0' || visited[i][j]) return;

        visited[i][j] = true;

        dfs(grid, i, j-1, visited);
        dfs(grid, i, j+1, visited);
        dfs(grid, i-1, j, visited);
        dfs(grid, i+1, j, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        vector<vector<int>>visited(n, vector<int>(m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(grid, i, j, visited);
                    count++;
                }
            }
        }

        return count;
    }
};