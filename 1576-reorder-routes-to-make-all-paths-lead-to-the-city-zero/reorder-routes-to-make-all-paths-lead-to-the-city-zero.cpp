class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>neighbors(n);
        vector<vector<int>>cV(n); //canVisit

        for(int i=0; i<connections.size(); i++){
            neighbors[connections[i][0]].push_back(connections[i][1]);
            neighbors[connections[i][1]].push_back(connections[i][0]);

            cV[connections[i][0]].push_back(connections[i][1]);
        }

        vector<bool>visited(n, false);
        queue<int>q;

        int count = 0;

        q.push(0);
        visited[0] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i=0; i<neighbors[node].size(); i++){
                int nX = neighbors[node][i];
                if(!visited[nX]){
                    for(int k=0; k<cV[node].size(); k++){
                        if(cV[node][k]==nX){
                            count++;
                            break;
                        }
                    }
                    q.push(nX);
                    visited[nX] = true;
                }
            }
        }

        return count;
    }
};