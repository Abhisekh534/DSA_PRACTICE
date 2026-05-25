class Solution {
public:
    bool dfs(vector<vector<char>>&board, string word, int i, int j, int index, vector<vector<int>>&visited){
        if(index==word.size()) return true;

        int n = board.size();
        int m = board[0].size();

        if(i<0 || i==n || j<0 || j==m || visited[i][j] || board[i][j]!=word[index]) return false;

        visited[i][j] = true;

        int left = dfs(board, word, i, j-1, index+1, visited);
        int right = dfs(board, word, i, j+1, index+1, visited);
        int top = dfs(board, word, i-1, j, index+1, visited);
        int down = dfs(board, word, i+1, j, index+1, visited);

        visited[i][j] = false;
        
        return left || right || top || down;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>>visited(n, vector<int>(m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dfs(board, word, i, j, 0, visited)) return true;
            }
        }

        return false;
    }
};