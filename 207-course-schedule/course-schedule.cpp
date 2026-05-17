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

        for(int i=0; i<numCourses; i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        // queue mein vahi courses enter kar rahe hain jinki dependencies poori ho chuki
        // par queue mein se elements aake jaa bhi rahe hain
        // to kitne total courses queue mein at some point of time aa chuke hain gin'ne ke liye count variable le sakte
        int count = 0;
        // count ham push karne ke time ya pop karne ke time kar skate hain

        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(int i=0; i<adj[node].size(); i++){
                int nextNode = adj[node][i];

                inDegree[nextNode]--;
                if(inDegree[nextNode]==0){
                    q.push(nextNode);
                }
            }
        }

        return (count==numCourses);
    }
};