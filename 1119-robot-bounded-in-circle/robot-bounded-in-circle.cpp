class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dir = 0; //0 = north , 1 = west, 2 = south, 3 = east
        int x = 0, y = 0;

        for(int i=0; i<instructions.size(); i++){
            if(instructions[i]=='L') dir = (dir+1)%4;
            if(instructions[i]=='R') dir = (dir+3)%4;

            if(instructions[i]=='G'){
                if(dir==0) y++;
                else if(dir==1) x--;
                else if(dir==2) y--;
                else x++;
            }
        }

        if((x==0 && y==0) || dir!=0) return true;
        return false;
    }
};