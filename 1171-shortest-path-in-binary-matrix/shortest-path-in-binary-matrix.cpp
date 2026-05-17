class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //bfs + direction matrix
        int n = grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return 1;

        vector<vector<int>>visited(n, vector<int>(n, false));

        queue<pair<int, int>>q;

        q.push({0, 0});
        visited[0][0] = true;

        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        int len = 1;

        while(!q.empty()){
            int qSize = q.size();

            while(qSize--){
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                if(x==n-1 && y==n-1) return len;

                for(int i=0; i<8; i++){
                    int ix = x + dx[i];
                    int iy = y + dy[i];

                    if(ix>-1 && ix<n && iy>-1 && iy<n && grid[ix][iy]!=1 && !visited[ix][iy]){
                        q.push({ix, iy});
                        visited[ix][iy] = true;
                    }
                }
            }

            len++;
        }

        return -1;

    }
};