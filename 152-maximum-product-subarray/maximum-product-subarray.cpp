class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmin = nums[0], currmax = nums[0], maxproduct = nums[0];

        for(int i=1; i<nums.size(); i++){
            int temp = currmax;
            currmax = max({currmax*nums[i], currmin*nums[i], nums[i]});
            currmin = min({currmin*nums[i], temp*nums[i], nums[i]});

            maxproduct = max(maxproduct, currmax);
        }

        return maxproduct;
    }
};