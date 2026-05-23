class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        vector<vector<int>>adjList(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                vector<int> f = bombs[i];
                vector<int> s = bombs[j];
                if( sqrt(pow((f[0]-s[0]), 2) + pow((f[1]-s[1]), 2))<=f[2] ){
                    adjList[i].push_back(j);
                }
            }
        }

        int maxCount = INT_MIN;

        for(int i=0; i<n; i++){
            queue<int>q;
            vector<int>visited(n, false);

            q.push(i);
            visited[i] = true;

            int count = 1;

            while(!q.empty()){
                int bomb = q.front();
                q.pop();

                for(int i=0; i<adjList[bomb].size(); i++){
                    int neighbor = adjList[bomb][i];
                    if(!visited[neighbor]){
                        q.push(neighbor);
                        visited[neighbor] = true;
                        count++;
                    }
                }
            }

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};