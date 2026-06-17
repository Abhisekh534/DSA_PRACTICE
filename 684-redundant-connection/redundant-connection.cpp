class Solution {
public:
    bool dfs(int source, int dest, vector<vector<int>>&adj, vector<int>&vis){

        if(source==dest) return true;

        vis[source] = true;

        for(int x : adj[source]){
            if(!vis[x]){
                if(dfs(x, dest, adj, vis)) return true;
            }
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>>adj(n+1);

        for(int i=0; i<n; i++){
            int source = edges[i][0];
            int dest = edges[i][1];

            //check previous indirect connection(using dfs) before adding this direct connection 
            
            vector<int>vis(n+1, false);

            if(dfs(source, dest, adj, vis)) return {source, dest};

            //because the control did not go to the return statement, therefore no previous connection
            //now make this connection

            adj[source].push_back(dest);
            adj[dest].push_back(source);
        }

        return {};
    }
};