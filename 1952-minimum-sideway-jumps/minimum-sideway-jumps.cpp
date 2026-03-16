class Solution {
public:
    int solve(vector<int>&obstacles, vector<vector<int>>&dp, int i, int position){
        int n = obstacles.size();
        if(i==n-1) return 0;

        if(dp[i][position-1]!=-1) return dp[i][position-1];

        int mini = INT_MAX;
        if(obstacles[i+1]==position){
            for(int j=1; j<4; j++){
                if(j!=position && j!=obstacles[i]){
                    mini = min(mini, 1 + solve(obstacles, dp, i+1, j));
                }
            }
        }else mini = solve(obstacles, dp, i+1, position);

        return dp[i][position-1] = mini;
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>>dp(n+1, vector<int>(3, -1));
        return solve(obstacles, dp, 0, 2);
    }
};