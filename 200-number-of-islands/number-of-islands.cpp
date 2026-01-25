class Solution {
public:
    void dfs(vector<vector<char>>&grid, vector<vector<bool>>&visited, int i, int j){
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
        if(visited[i][j] || grid[i][j]=='0') return;
        
        visited[i][j] = true;
        
        dfs(grid, visited, i+1, j);
        dfs(grid, visited, i-1, j);
        dfs(grid, visited, i, j+1);
        dfs(grid, visited, i, j-1);

    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>visited(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(grid, visited, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};