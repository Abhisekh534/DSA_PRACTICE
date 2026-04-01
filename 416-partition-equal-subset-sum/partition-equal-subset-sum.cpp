class Solution {
public:
    bool solve(vector<int>&nums, vector<vector<int>>&dp, int index, int target){
        if(target==0) return true;

        if(target<0) return false;
        if(index==nums.size()) return false;

        if(dp[index][target]!=-1) return dp[index][target];

        return dp[index][target] = (solve(nums, dp, index+1, target-nums[index]) || solve(nums, dp, index+1, target));
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x : nums) sum+=x;

        if(sum%2==1) return false;

        vector<vector<int>>dp(nums.size(), vector<int>(sum/2+1, -1));

        return solve(nums, dp, 0, sum/2);
    }
};