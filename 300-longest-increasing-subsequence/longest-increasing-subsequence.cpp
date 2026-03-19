class Solution {
public:
    int solve(vector<int>&nums, vector<int>&LIS, int i){
        int n = nums.size();

        if(LIS[i]!=-1) return LIS[i];

        LIS[i] = 1;

        for(int j=i+1; j<n; j++){
            if(nums[i]<nums[j]) LIS[i] = max(LIS[i], 1+solve(nums, LIS, j));
        }

        return LIS[i];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>LIS(n, -1);

        int maxi = 1;

        for(int i=0; i<n-1; i++){
            maxi = max(maxi, solve(nums, LIS, i));
        }

        return maxi;
    }
};