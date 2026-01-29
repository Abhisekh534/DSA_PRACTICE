class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, vector<vector<bool>>&visited, bool& f){
        if(i<0 || j<0 || i>=grid2.size() || j>=grid2[0].size()) return;
        if(visited[i][j] || grid2[i][j]==0) return;

        visited[i][j] = true;
        if(grid1[i][j]==0) f = false;

        dfs(grid1, grid2, i+1, j, visited, f);
        dfs(grid1, grid2, i-1, j, visited, f);
        dfs(grid1, grid2, i, j+1, visited, f);
        dfs(grid1, grid2, i, j-1, visited, f);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<bool>>visited(grid2.size(), vector<bool>(grid2[0].size(), false));

        int count = 0;
        for(int i=0; i<grid2.size(); i++){
            for(int j=0; j<grid2[0].size(); j++){
                if(grid2[i][j]==1 && !visited[i][j]){
                    bool f = true;
                    dfs(grid1, grid2, i, j, visited, f);
                    if(f) count++;
                }
            }
        }

        return count;
    }
};