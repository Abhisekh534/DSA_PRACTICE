class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;

        for(int x : nums){
            sum = max(x, sum+x);
            maxi = max(maxi, sum);
        }

        return maxi;
    }
};