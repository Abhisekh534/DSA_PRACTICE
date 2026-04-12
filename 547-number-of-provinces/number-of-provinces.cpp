class Solution {
public:
    int n;

    void dfs(vector<vector<int>>&isConnected, int i, vector<bool>&visited){
        visited[i] = true;

        for(int j=0; j<n; j++){
            if(isConnected[i][j]==1 && !visited[j]) dfs(isConnected, j, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<bool>visited(n, false);

        int count = 0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(isConnected, i, visited);
            }
        }

        return count;
    }
};