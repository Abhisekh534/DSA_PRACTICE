class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n+1);

        for(vector<int> x : times){
            adj[x[0]].push_back({x[1], x[2]});
        }

        vector<int>distance(n+1, INT_MAX);
        distance[k] = 0;

        queue<pair<int, int>>q;
        q.push({k, 0});

        while(!q.empty()){
            int node = q.front().first;
            int weight = q.front().second;
            q.pop();

            for(int i=0; i<adj[node].size(); i++){
                int neighbor = adj[node][i].first;
                int neighborDist = adj[node][i].second;

                if(weight + neighborDist < distance[neighbor]){
                    distance[neighbor] = weight + neighborDist;
                    q.push({neighbor, distance[neighbor]});
                }
            }
        }

        int maxi = INT_MIN;

        for(int i=1; i<distance.size(); i++){
            if(distance[i]==INT_MAX) return -1;
            maxi = max(maxi, distance[i]);
        }

        return maxi;
    }
};