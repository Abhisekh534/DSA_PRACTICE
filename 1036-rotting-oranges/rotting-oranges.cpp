class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>>q;
        int t = 0;
        int ocount = 0; //orange count

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                }else if(grid[i][j]==1) ocount++;
            }
        }

        int qcount = q.size(); //count for a single level of oranges in a queue
        //when all oranges of a single level are popped from the queue , and of next level are added t+=1

        int u[4] = {0, 0, 1, -1};
        int v[4] = {1, -1, 0, 0};

        while(!q.empty()){
            if(qcount==0){
                qcount = q.size();
                t++;
            }
            auto[x, y] = q.front();
            q.pop();
            qcount--;

            for(int i=0; i<4; i++){
                int kx = x + u[i];
                int ky = y + v[i];

                if(kx>-1 && kx<n && ky>-1 && ky<m){
                    if(grid[kx][ky]==1){
                        grid[kx][ky] = 2;
                        ocount--;
                        q.push({kx, ky});
                    }
                }
            }
        }

        if(ocount==0) return t;
        else return -1;
    }
};