class Solution {
public:
    void dfs(vector<vector<int>>&isConnected, vector<bool>&visited, int index){
        visited[index] = true;

        for(int j=0; j<isConnected[index].size(); j++){
            if(isConnected[index][j]==1 && !visited[j]){
                dfs(isConnected, visited, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<bool>visited(isConnected.size(), false);

        for(int i=0; i<isConnected.size(); i++){
            if(!visited[i]){
                count++;
                dfs(isConnected, visited, i);
            }
        }

        return count;
    }
};