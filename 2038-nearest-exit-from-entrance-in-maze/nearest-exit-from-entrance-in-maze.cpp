class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        vector<vector<int>>visited(n, vector<int>(m, false));

        queue<pair<int, int>>q;
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;

        int steps = 0;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while(!q.empty()){
            int qSize = q.size();

            while(qSize--){
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                if((x==0 || x==n-1 || y==0 || y==m-1) && !(x==entrance[0] && y==entrance[1])) return steps;
                //maze[x][y]=='.' check karna zaroori nahi hai kyunki queue mein ham sirf . hi daal rahe hain

                for(int i=0; i<4; i++){
                    int ix = x + dx[i];
                    int iy = y + dy[i];

                    if(ix>-1 && ix<n && iy>-1 && iy<m && maze[ix][iy]=='.' && !visited[ix][iy]){
                        q.push({ix, iy});
                        visited[ix][iy] = true;
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};