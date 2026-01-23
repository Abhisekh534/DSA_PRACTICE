class Solution {
public:
    bool solve(vector<int>&nums, vector<int>&dp, int index){
        if(index>=nums.size()) return false;

        if(index==nums.size()-1) return true;

        if(dp[index]!=-1) return dp[index];

        for(int i=1; i<=nums[index]; i++){
            if(solve(nums, dp, index+i)){
                dp[index] = true;
                return true;
            }
        }

        dp[index] = 0;
        return false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return solve(nums, dp, 0);
    }
};