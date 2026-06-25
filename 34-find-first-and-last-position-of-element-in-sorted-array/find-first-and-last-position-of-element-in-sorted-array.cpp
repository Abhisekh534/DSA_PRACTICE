class Solution {
public:
    int lowerBound(vector<int>&nums, int target){
        int l = 0, r = nums.size()-1, mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid]>=target) r = mid - 1;
            else l = mid + 1;
        }

        if(l<nums.size() && nums[l]==target) return l;
        return -1;
    }

    int upperBound(vector<int>&nums, int target){
        int l = 0, r = nums.size()-1, mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid]>target) r = mid - 1;
            else l = mid + 1;
        }

        if(r>-1 && nums[r]==target) return r;
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1, -1};
        
        vector<int> ans(2, -1);

        ans[0] = lowerBound(nums, target);
        ans[1] = upperBound(nums, target);

        return ans;
    }
};