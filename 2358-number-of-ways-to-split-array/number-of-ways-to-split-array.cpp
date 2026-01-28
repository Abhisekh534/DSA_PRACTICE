class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0;
        for(int i=0; i<nums.size(); i++) totalSum+=nums[i];

        int count = 0;
        long long tempSum = 0;

        for(int i=0; i<nums.size()-1; i++){
            tempSum+=nums[i];
            if(2*tempSum>=totalSum) count++;
        }

        return count;
    }
};