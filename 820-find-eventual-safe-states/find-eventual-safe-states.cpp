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
        vector<bool>isSafe(n, false);

        for(int i=0; i<n; i++){
            if(outDegree[i]==0){
                q.push(i);
                isSafe[i]=true;
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i=0; i<graphM[node].size(); i++){
                int pred = graphM[node][i];

                bool flag = true;

                for(int j=0; j<graph[pred].size(); j++){
                    int succPred = graph[pred][j];
                    if(!isSafe[succPred]) flag = false;
                }

                if(flag){
                    isSafe[pred] = true;
                    q.push(pred);
                }
            }
        }

        vector<int>ans;
        for(int i=0; i<n; i++) if(isSafe[i]) ans.push_back(i);
        return ans;
    }
};