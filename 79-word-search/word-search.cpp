class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>&board, string word, int index, vector<vector<bool>>&visited){
        int n = board.size(), m = board[0].size();
        if(index == word.size()) return true;

        if(i<0 || i==n || j<0 || j==m || board[i][j]!=word[index] || visited[i][j]) return false;

        visited[i][j] = true;

        bool result = (dfs(i, j-1, board, word, index+1, visited) ||
                        dfs(i, j+1, board, word, index+1, visited) ||
                        dfs(i-1, j, board, word, index+1, visited) ||
                        dfs(i+1, j, board, word, index+1, visited)
                        );

        visited[i][j] = false;

        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>>visited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dfs(i, j, board, word, 0, visited)) return true;
            }
        }
        
        return false;
    }
};