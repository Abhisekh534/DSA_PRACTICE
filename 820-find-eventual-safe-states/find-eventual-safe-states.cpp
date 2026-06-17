class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>graphM(n);

        vector<int>outDegree(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].size(); j++){
                graphM[graph[i][j]].push_back(i);
                outDegree[i]++;
            }
        }

        queue<int>q;
        vector<int>ans;

        for(int i=0; i<n; i++){
            if(outDegree[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i=0; i<graphM[node].size(); i++){
                int previous = graphM[node][i];

                outDegree[previous]--;

                if(outDegree[previous]==0){
                    q.push(previous);
                    ans.push_back(previous);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};