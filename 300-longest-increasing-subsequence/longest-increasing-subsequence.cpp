class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>LIS(n, 1);

        int maxi = 1;
        for(int i=n-2; i>-1; i--){
            for(int j=i+1; j<n; j++){
                if(nums[i]<nums[j]) LIS[i] = max(LIS[i], 1 + LIS[j]);
            }
            maxi = max(maxi, LIS[i]);
        }

        return maxi;
    }
};