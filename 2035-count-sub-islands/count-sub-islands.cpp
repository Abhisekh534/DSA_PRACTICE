class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool& f){
        if(i<0 || j<0 || i>=grid2.size() || j>=grid2[0].size()) return;
        if(grid2[i][j]==0) return;

        if(grid1[i][j]==0) f = false;
        
        grid2[i][j] = 0; // once visited mark 0, works like visited matrix

        dfs(grid1, grid2, i+1, j, f);
        dfs(grid1, grid2, i-1, j, f);
        dfs(grid1, grid2, i, j+1, f);
        dfs(grid1, grid2, i, j-1, f);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int count = 0;
        for(int i=0; i<grid2.size(); i++){
            for(int j=0; j<grid2[0].size(); j++){
                if(grid2[i][j]==1){
                    bool f = true;
                    dfs(grid1, grid2, i, j, f);
                    if(f) count++;
                }
            }
        }

        return count;
    }
};