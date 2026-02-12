class Solution {
public:
    int solve(vector<int>&nums, vector<int>&dp, int index, int n){
        if(index>=n) return 0;

        if(dp[index]!=-1) return dp[index];

        int take = nums[index] + solve(nums, dp, index+2, n);
        int skip = solve(nums, dp, index+1, n);

        return dp[index] = max(skip, take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1) return nums[0];

        vector<int>dp1(n, -1);
        vector<int>dp2(n, -1);

        return max(solve(nums, dp1, 0, n-1), solve(nums, dp2, 1, n));
    }
};