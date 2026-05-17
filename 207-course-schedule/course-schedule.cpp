class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDegree(numCourses, 0);
        vector<vector<int>>adj(numCourses);

        for(vector<int> x : prerequisites){
            inDegree[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }

        queue<int>q;
        // queue mein jo bhi courses enter kar rahe hain yaani ki vo complete kiye jaa sakte hain
        // par queue mein se elements aake jaa bhi rahe hain
        // to kitne total courses queue mein at some point of time aa chuke hain gin'ne ke liye count variable le sakte
        int count = 0;

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
                int nextNode = adj[node][i];

                inDegree[nextNode]--;
                if(inDegree[nextNode]==0){
                    q.push(nextNode);
                    count++;
                }
            }
        }

        return (count==numCourses);
    }
};