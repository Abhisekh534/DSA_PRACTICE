class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adjList(n);

        for(vector<int>x : flights){
            adjList[x[0]].push_back({x[1], x[2]});
        }

        vector<int>dist(n, INT_MAX);

        queue<pair<int, int>>q;

        q.push({src, 0});
        dist[src] = 0;

        int stops = -1;

        int minPrice = INT_MAX;

        while(!q.empty() && stops<=k){
            int qSize = q.size();
            while(qSize--){
                int curr = q.front().first;
                int price = q.front().second;
                q.pop();

                if(curr==dst) minPrice = min(price, minPrice);

                for(pair<int, int>x : adjList[curr]){
                    if(price+ x.second < dist[x.first]){
                        q.push({x.first, price+x.second});
                        dist[x.first] = price+x.second;
                    }
                }
            }
            stops++;
        }

        if(minPrice!=INT_MAX) return minPrice;
        return -1;
    }
};