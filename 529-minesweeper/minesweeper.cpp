class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size();
        int m = board[0].size();
        
        int x = click[0], y = click[1];

        if(board[x][y]=='M'){
            board[x][y] = 'X';
        }


        else if(board[x][y]=='E'){
            int dirX[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int dirY[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
            
            queue<pair<int, int>>q;
            vector<vector<int>>visited(n, vector<int>(m, false));

            q.push({x, y});
            visited[x][y] = true;

            while(!q.empty()){
                int nodeX = q.front().first;
                int nodeY = q.front().second;
                q.pop();

                int count = 0;
            
                for(int k=0; k<8; k++){
                    int kx = nodeX + dirX[k];
                    int ky = nodeY + dirY[k];

                    if(kx>-1 && kx<n && ky>-1 && ky<m){
                        if(board[kx][ky]=='M') count++;
                    }
                }

                if(count==0){
                    board[nodeX][nodeY] = 'B';

                    for(int k=0; k<8; k++){
                        int kx = nodeX + dirX[k];
                        int ky = nodeY + dirY[k];

                        if(kx>-1 && kx<n && ky>-1 && ky<m){
                            if(!visited[kx][ky] && board[kx][ky]=='E'){
                                q.push({kx, ky});
                                visited[kx][ky] = true;
                            }
                        }
                    }
                    
                }
                else board[nodeX][nodeY] = count + '0';
            }
        }

        return board;
    }
};