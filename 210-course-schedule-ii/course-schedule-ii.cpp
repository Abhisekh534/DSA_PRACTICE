class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int>inDegree(numCourses, 0);

        for(int i=0; i<adj.size(); i++){
            for(int j=0; j<adj[i].size(); j++){
                inDegree[adj[i][j]]++;
            }
        }

        queue<int>q;
        vector<int>topo;

        for(int i=0; i<numCourses; i++){
            if(inDegree[i]==0){
                q.push(i);
                topo.push_back(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0; i<adj[node].size(); i++){
                int neighbor = adj[node][i];
                inDegree[neighbor]--;
                if(inDegree[neighbor]==0){
                    q.push(neighbor);
                    topo.push_back(neighbor);
                }
            }
        }

        if(topo.size()==numCourses) return topo;
        return {};
    }
};
