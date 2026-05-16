class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n, false);

        int notVisited = n;

        queue<int>q;

        q.push(0);
        visited[0] = true;
        notVisited--;

        while(!q.empty()){
            int room = q.front();
            q.pop();

            for(int i=0; i<rooms[room].size(); i++){
                int nextRoom = rooms[room][i];
                if(!visited[nextRoom]){
                    q.push(nextRoom);
                    visited[nextRoom] = true;
                    notVisited--;
                }
            }
        }

        return (!notVisited);
    }
};