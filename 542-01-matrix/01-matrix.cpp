class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>>q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        //direction vectors for checking the four direction using a loop
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int k=0; k<4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    if(dist[x][y]+1<dist[nx][ny]){
                        dist[nx][ny] = 1 + dist[x][y];
                        q.push({nx, ny});
                    }
                }
            }
        }

        return dist;
    }
};