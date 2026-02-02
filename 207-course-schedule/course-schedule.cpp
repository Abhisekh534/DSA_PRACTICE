class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses, 0);

        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }

        queue<int>q;
        int count = 0;
        //instaed of using extra memory for topo sort , we can just count the number of nodes which will qualify for array topo
        //and compare it with the number of nodes, count = number of nodes -> no cycle/deadlock
        //count <> number of nodes -> cycle/deadlock present
         
        for(int i=0; i<numCourses; i++){
            if(inDegree[i]==0){
                q.push(i);
                count++;
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
                    count++;
                }
            
            }
        }

        if(count==numCourses) return true;
        return false;
    }
};