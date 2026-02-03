class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>graphM(n);

        vector<int>outDegree(n, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].size(); j++){
                graphM[graph[i][j]].push_back(i);
                outDegree[i]++;
            }
        }

        queue<int>q;
        vector<int>isSafe(n, false);
        //isSafe na use karke direct bhi safe nodes ko vector<ans> mein daal sakte hain
        //par vo sorted nahi hoga aur sort karne mein time complexity badh jaayegi
        //isSafe se extra memory lagegi par vector<ans> mein ek pass mein saare nodes sorted order me aa jaayenge

        for(int i=0; i<n; i++){
            if(outDegree[i]==0){
                q.push(i);
                isSafe[i] = true;
            }
        }


        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i=0; i<graphM[node].size(); i++){

                int predecessor = graphM[node][i];

                outDegree[predecessor]--;

                if(outDegree[predecessor]==0){
                    q.push(predecessor);
                    isSafe[predecessor] = true;
                }

            }
        }

        vector<int>ans;

        for(int i=0; i<n; i++){
            if(isSafe[i]) ans.push_back(i);
        }

        return ans;
    }
};