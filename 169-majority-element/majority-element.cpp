class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0;
        int winner;

        for(int i=0; i<nums.size(); i++){
            if(freq==0) winner = nums[i];

            if(nums[i]==winner) freq++;
            else freq--;
        }

        return winner;
    }
};