class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>vec(nums.size());
        int i=0, j=nums.size()/2;
        
        for(int k=0; k<nums.size(); k++){
            if(nums[k]>0) vec[i++] = nums[k];
            else vec[j++] = nums[k];
        }

        i=0, j=nums.size()/2;

        for(int k=0; k<nums.size()/2; k++){
            nums[2*k] = vec[i++];
            nums[2*k+1] = vec[j++];
        }

        return nums;
    }
};