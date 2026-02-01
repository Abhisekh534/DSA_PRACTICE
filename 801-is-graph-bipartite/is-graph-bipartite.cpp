class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);//-1 means no color till now

        
        queue<int>q;
        for(int i=0; i<n; i++){
            if(color[i]==-1){
                q.push(i);
                color[i] = 0;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(int i=0; i<graph[node].size(); i++){
                        int neighbor = graph[node][i];
                        if(color[neighbor]!=-1){
                            if(color[neighbor]==color[node]) return false;
                        }else{
                            color[neighbor] = 1 - color[node];
                            q.push(neighbor);
                        }
                    }
                }
            }

        }

        return true;
    }
};