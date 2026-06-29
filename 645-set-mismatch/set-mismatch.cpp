class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), sum = 0, x;
        for(int i=0; i<n-1; i++){
            if(nums[i]==nums[i+1]){
                x = nums[i];
                break;
            }
        }
        
        for(int i=0; i<n; i++) sum+=nums[i];

        int z = n*(n+1)/2;
        if(sum>z) return {x, x - (sum-z)};
        return {x, x+z-sum};
    }
};