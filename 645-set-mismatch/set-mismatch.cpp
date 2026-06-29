class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int x, y, sum = 0;;
        
        vector<bool>isPresent(n+1, false);
        for(int num : nums){
            if(isPresent[num]) x = num;
            isPresent[num] = true;
            sum+=num;
        }

        return {x, x + (n*(n+1)/2) - sum};
    }
};