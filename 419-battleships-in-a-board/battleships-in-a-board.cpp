class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));

        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && board[i][j]=='X'){
                    count++;
                    visited[i][j] = true;

                    int x = i, y = j+1;
                    while(y<m && board[x][y]){
                        if(board[x][y]=='X'){
                            visited[x][y] = true;
                            y++;
                        }else break;
                    }

                    x = i+1, y = j;
                    while(x<n && board[x][y]){
                        if(board[x][y]=='X'){
                            visited[x][y] = true;
                            x++;
                        }else break;
                    }
                }
            }
        }

        return count;
    }
};