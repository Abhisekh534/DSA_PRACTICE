class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        //without using visited matrix
        //visited me mark karne ki jagah seedha board me X ko . karte jaayenge
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='X'){
                    count++;
                    board[i][j] = '.';

                    int x = i, y = j+1;
                    while(y<m && board[x][y]){
                        if(board[x][y]=='X'){
                            board[x][y] = '.';
                            y++;
                        }else break;
                    }

                    x = i+1, y = j;
                    while(x<n && board[x][y]){
                        if(board[x][y]=='X'){
                            board[x][y] = '.';
                            x++;
                        }else break;
                    }
                }
            }
        }

        return count;
    }
};