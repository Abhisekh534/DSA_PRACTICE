class Solution {
public:
    bool dfs(vector<vector<char>>&board, string word, int i, int j, int index){
        if(index==word.size()) return true;

        int n = board.size();
        int m = board[0].size();

        if(i<0 || i==n || j<0 || j==m || board[i][j]=='#' || board[i][j]!=word[index]) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        int found = dfs(board, word, i, j-1, index+1) || 
                    dfs(board, word, i, j+1, index+1) ||
                    dfs(board, word, i-1, j, index+1) ||
                    dfs(board, word, i+1, j, index+1);

        //alag se left right top bottom calculate karne se 4 recursive calls chali jaayengi no matter ki first call me hi true mil jaaye aur baaki calls redundant ho jaaye

        board[i][j] = temp;
        
        return found;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dfs(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }
};