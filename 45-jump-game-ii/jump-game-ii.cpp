class Solution {
public:
    int solve(vector<int>&nums, vector<int>&dp, int index){
        if(index>=nums.size()-1) return 0;

        if(dp[index]!=-1) return dp[index];

        int ans = INT_MAX;

        for(int i=1; i<=nums[index]; i++){
            int next = solve(nums, dp, index+i);

            if(next!=INT_MAX){
                ans = min(ans, 1+next);
            }
        }

        return dp[index] = ans;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return solve(nums, dp, 0);
    }
};