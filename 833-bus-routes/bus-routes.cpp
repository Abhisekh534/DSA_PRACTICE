class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>>map;
        //mapping bus stops to all the routes they are present in

        for(int i=0; i<routes.size(); i++){
            for(int x : routes[i]) map[x].push_back(i);
        }

        vector<int>visited(500, false);

        queue<int>q;
        q.push(source);

        int len = 0;

        while(!q.empty()){
            int qSize = q.size();
            while(qSize--){
                int stop = q.front();
                q.pop();
                if(stop==target) return len;
                for(int route : map[stop]){
                    if(!visited[route]){
                        visited[route] = true;

                        for(int nextStop : routes[route]){
                            q.push(nextStop);
                        }
                    }
                }
            }
            len++;
        }

        return -1;

    }
};