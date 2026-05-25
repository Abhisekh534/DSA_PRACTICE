class Solution {
public:
    void dfs(vector<vector<int>>&ans, vector<vector<int>>&graph, vector<int>&temp, vector<int>&visited, int node){
        int n = graph.size();

        if(visited[node]) return;

        temp.push_back(node);
        visited[node] = true;

        if(node==n-1){
            ans.push_back(temp);
        }

        for(int j=0; j<graph[node].size(); j++){
            int nextNode = graph[node][j];
            dfs(ans, graph, temp, visited, nextNode);
        }

        temp.pop_back();
        visited[node] = false;

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>visited(n, false);

        dfs(ans, graph, temp, visited, 0);

        return ans;
    }
};