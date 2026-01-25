class Solution {
public:
    void dfs(vector<vector<char>>&grid, int i, int j){
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
        if(grid[i][j]=='0') return;
        
        //jahaan khade ho use check karo na ki possible next steps ko

        grid[i][j] = '0';

        //instead of calling dfs function 4 times , we can create direction arrays and use a loop

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        for(int k=0; k<4; k++){
            dfs(grid, i+dx[k], j+dy[k]);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        //visited use na karke seedha grid me hi 1 ko 0 kar denge udhar dobara jaayega hi nahi
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};