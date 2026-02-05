class Solution {
public:

    bool dfs(vector<vector<int>>&grid, int i, int j, int value, vector<vector<bool>>&visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j]) return false;
        if(grid[i][j]>value) return false;

        visited[i][j] = true;

        if(i==grid.size()-1 && j==grid[0].size()-1) return true;

        return (dfs(grid, i+1, j, value, visited) || dfs(grid, i-1, j, value, visited) || dfs(grid, i, j+1, value, visited) || dfs(grid, i, j-1, value, visited));
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                maxi = max(maxi, grid[i][j]);
            }
        }
        int ans = 0;
        int l=grid[n-1][m-1];
        int e = maxi;

        int mid = l + (e-l)/2;
        while(l<=e){
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            if(dfs(grid, 0, 0, mid, visited)){
                ans = mid;
                e = mid - 1;
            }else l = mid+1;

            mid = l+ (e-l)/2;
        } 

        return ans;
    }
};