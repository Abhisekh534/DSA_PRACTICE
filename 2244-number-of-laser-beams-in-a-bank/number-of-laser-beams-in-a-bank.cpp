class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int previousRow = 0;
        int row = 0;
        for(int i=0; i<bank.size(); i++){
            for(int j=0; j<bank[0].size(); j++){
                if(bank[i][j]=='1') row++;
            }
            
            if(row!=0){
                if(previousRow!=0) ans+=(row*previousRow);
                previousRow = row;
                row = 0;
            }
        }

        return ans;
    }
};