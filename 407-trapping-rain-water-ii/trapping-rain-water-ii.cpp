class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int ans = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        int n=heightMap.size(), m=heightMap[0].size();

        vector<vector<int>>visited(n, vector<int>(m, false));

        for(int i=0; i<n; i++){
            pq.push({heightMap[i][0], i, 0});
            visited[i][0] = true;
            pq.push({heightMap[i][m-1], i, m-1});
            visited[i][m-1] = true;
        }
        for(int j=0; j<m; j++){
            pq.push({heightMap[0][j], 0, j});
            visited[0][j] = true;
            pq.push({heightMap[n-1][j], n-1, j});
            visited[n-1][j] = true;
        }


        while(!pq.empty()){
            int height = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];

            pq.pop();
            ans+=(height-heightMap[x][y]);

            int kx[4] = {-1, 1, 0, 0};
            int ky[4] = {0, 0, 1, -1};

            for(int i=0; i<4; i++){
                int nx = x + kx[i];
                int ny = y + ky[i];

                if(nx>0 && nx<n && ny>0 && ny<m && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    if(heightMap[nx][ny]>height) pq.push({heightMap[nx][ny], nx, ny});
                    else pq.push({height, nx, ny});
                }
            }
        }

        return ans;
    }
};