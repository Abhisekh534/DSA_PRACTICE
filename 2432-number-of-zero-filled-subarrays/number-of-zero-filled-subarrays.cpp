class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long numSum = 0;
        int i = 0;
        while(i<nums.size()){
            
            if(nums[i]!=0) i++;

            else{
                long long count = 0;
                while(i<nums.size() && nums[i]==0){
                    count++;
                    i++;
                }
                numSum+=((count*(count+1))/2);
            }
        
        }

        return numSum;
    }
};