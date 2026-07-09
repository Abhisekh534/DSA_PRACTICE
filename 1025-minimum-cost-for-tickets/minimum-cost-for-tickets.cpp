class Solution {
public:
    int solve(vector<int>&days, vector<int>&costs, int i, vector<int>&dp){
        int n = days.size();

        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        int one = costs[0] + solve(days, costs, i+1, dp);

        int x = i;
        while(x<n && days[x]<days[i]+7) x++;
        int seven = costs[1] + solve(days, costs, x, dp);

        x = i;
        while(x<n && days[x]<days[i]+30) x++;
        int thirty = costs[2] + solve(days, costs, x, dp);

        return dp[i] = min({one, seven, thirty});

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n, -1);

        return solve(days, costs, 0, dp);
    }
};