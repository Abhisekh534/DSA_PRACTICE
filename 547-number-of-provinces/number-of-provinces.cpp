class Solution {
public:

    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int index){
        visited[index] = true;

        for(int i=0; i<isConnected[index].size(); i++){
            if(isConnected[index][i] && !visited[i]) dfs(isConnected, visited, i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        int count = 0;
        vector<bool>visited(n, false);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(isConnected, visited, i);
            }
        }

        return count;
    }
};