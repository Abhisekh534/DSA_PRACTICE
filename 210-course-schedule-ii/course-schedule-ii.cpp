class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDegree(numCourses, 0);
        vector<vector<int>>adj(numCourses);

        for(vector<int> x : prerequisites){
            inDegree[x[0]]++;
            adj[x[1]].push_back(x[0]);
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
                int nextNode = adj[node][i];

                inDegree[nextNode]--;
                if(inDegree[nextNode]==0){
                    q.push(nextNode);
                    topo.push_back(nextNode);
                }
            }
        }

        if(topo.size()==numCourses) return topo;
        else return {};
    }
};