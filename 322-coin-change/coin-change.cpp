class Solution {
public:
    int solve(vector<int>&coins, vector<int>&dp, int amount){
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;

        if(dp[amount]!=-1) return dp[amount];

        int mini = INT_MAX;

        for(int coin : coins){
            int ans = solve(coins, dp, amount-coin);

            if(ans!=INT_MAX) mini = min(mini, 1+ans);
        }

        return dp[amount] = mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, -1);

        int ans = solve(coins, dp, amount);

        return (ans==INT_MAX) ? -1 : ans;
    }
};