class Solution {
public:
    bool dfs(int i, int j, int parx, int pary, vector<vector<char>>&grid, vector<vector<bool>>&visited){
        int n = grid.size();
        int m = grid[0].size();

        if(i<0 || i==n || j<0 || j==m || grid[i][j]!=grid[parx][pary]) return false;

        if(visited[i][j]) return true;

        visited[i][j] = true;

        bool result = false;

        int kx[4] = {0, 0, 1, -1};
        int ky[4] = {-1, 1, 0, 0};

        for(int k=0; k<4; k++){
            int nx = i + kx[k];
            int ny = j + ky[k];

            if(!(nx==parx && ny==pary)) result = result || dfs(nx, ny, i, j, grid, visited);
        }

        return result;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>visited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && dfs(i, j, i,j, grid, visited)) return true;
            }
        }

        return false;
    }
};