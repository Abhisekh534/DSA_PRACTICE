class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>vec(nums.size());
        int pos = 0, neg = 1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                vec[pos] = nums[i];
                pos+=2;
            }
            else{
                vec[neg] = nums[i];
                neg+=2;
            }
        }

        return vec;
    }
};