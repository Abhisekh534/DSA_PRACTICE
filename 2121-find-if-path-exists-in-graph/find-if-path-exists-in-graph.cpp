class Solution {
public:
    bool dfs(int n, vector<vector<int>>&adj, int source , int destination, vector<bool>&visited){
        if(source==destination) return true;

        visited[source] = true;

        for(int i=0; i<adj[source].size(); i++){
            int neighbor = adj[source][i];

            if(!visited[neighbor]){
                if(dfs(n, adj, neighbor, destination, visited)) return true;
            }
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);

        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool>visited(n, false);
        
        return dfs(n, adj, source, destination, visited);
    }
};