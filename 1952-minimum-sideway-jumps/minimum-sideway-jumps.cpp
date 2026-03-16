class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int>dp = {1, 0, 1};
        
        for(int i=1; i<n; i++){
            if(obstacles[i]!=0) dp[obstacles[i]-1] = 1e9;

            if(obstacles[i]!=1) dp[0] = min({dp[0], 1+dp[1], 1+dp[2]});
            if(obstacles[i]!=2) dp[1] = min({dp[1], 1+dp[0], 1+dp[2]});
            if(obstacles[i]!=3) dp[2] = min({dp[2], 1+dp[0], 1+dp[1]});
        }

        return min({dp[0], dp[1], dp[2]});
    }
};