class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>>st;

        for(int i=0; i<obstacles.size(); i++){
            st.insert({obstacles[i][0], obstacles[i][1]});
        }

        int dir = 0; // 0 = north, 1 = west, 2 = south, 3 = east
        int x = 0, y = 0;

        int maxDist = 0;
        for(int i=0; i<commands.size(); i++){
            if(commands[i]==-2) dir = (dir+1)%4;
            else if(commands[i]==-1) dir = ((dir-1)%4 + 4)%4;

            else{
                if(dir==0){
                    for(int j=0; j<commands[i]; j++){
                        if(st.find({x, y+1})!=st.end()) break;
                        y++;
                    }
                }
                else if(dir==1){
                    for(int j=0; j<commands[i]; j++){
                        if(st.find({x-1, y})!=st.end()) break;
                        x--;
                    }
                }
                else if(dir==2){
                    for(int j=0; j<commands[i]; j++){
                        if(st.find({x, y-1})!=st.end()) break;
                        y--;
                    }
                }
                else{
                    for(int j=0; j<commands[i]; j++){
                        if(st.find({x+1, y})!=st.end()) break;
                        x++;
                    }
                }
            }
            maxDist = max(maxDist, x*x + y*y);
        }

        return maxDist;
    }
};