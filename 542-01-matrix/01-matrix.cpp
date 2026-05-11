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

        int u[4] = {0, 0, 1, -1};
        int v[4] = {1, -1, 0, 0};

        while(!q.empty()){
            auto[x, y] = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int kx = x + u[i];
                int ky = y + v[i];

                if(kx>-1 && kx<n && ky>-1 && ky<m){
                    if(dist[kx][ky]==INT_MAX){
                        dist[kx][ky] = dist[x][y] + 1;
                        q.push({kx, ky});
                    }
                }
            }
        }

        return dist;

    }
};