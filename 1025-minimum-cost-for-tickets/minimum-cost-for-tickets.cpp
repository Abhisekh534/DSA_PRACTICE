class Solution {
public:
    int solve(vector<int>&days, vector<int>&costs, vector<int>&dp, int i){
        int n = days.size();
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];
        
        int one = costs[0] + solve(days, costs, dp, i+1);
        
        int x = i;
        while(x<n && days[x]<=days[i]+6) x++;
        int seven = costs[1] + solve(days, costs, dp, x);

        x = i;
        while(x<n && days[x]<=days[i]+29) x++;
        int thirty = costs[2] + solve(days, costs, dp, x);

        return dp[i] = min({one, seven, thirty});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n, -1);

        return solve(days, costs, dp, 0);
    }
};