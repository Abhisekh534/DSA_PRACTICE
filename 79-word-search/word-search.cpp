class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>&board, string word, int index){
        int n = board.size(), m = board[0].size();
        if(index == word.size()) return true;

        if(i<0 || i==n || j<0 || j==m || board[i][j]!=word[index]) return false;

        char temp = word[index];
        board[i][j] = '#';

        bool result = dfs(i, j-1, board, word, index+1) ||
                    dfs(i, j+1, board, word, index+1) ||
                    dfs(i-1, j, board, word, index+1) ||
                    dfs(i+1, j, board, word, index+1);
        
        board[i][j] = temp;

        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dfs(i, j, board, word, 0)) return true;
            }
        }
        
        return false;
    }
};