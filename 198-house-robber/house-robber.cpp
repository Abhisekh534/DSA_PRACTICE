class Solution {
public:
    int solve(vector<int>&nums, vector<int>&dp, int index){
        if(index>=nums.size()) return 0;

        if(dp[index]!=-1) return dp[index];

        int take = nums[index] + solve(nums, dp, index+2);
        int skip = solve(nums, dp, index+1);

        return dp[index] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);

        return solve(nums, dp, 0);
    }
};