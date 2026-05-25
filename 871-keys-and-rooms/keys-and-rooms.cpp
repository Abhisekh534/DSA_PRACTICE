class Solution {
public:
    void dfs(vector<vector<int>>&rooms, vector<int>&visited, int i, int&count){
        if(visited[i]) return;

        visited[i] = true;
        count++;

        for(int j=0; j<rooms[i].size(); j++){
            dfs(rooms, visited, rooms[i][j], count);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n, false);

        int count = 0;

        dfs(rooms, visited, 0, count);

        return (count==n);
    }
};