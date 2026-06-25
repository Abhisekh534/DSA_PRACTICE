class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1, -1};
        
        vector<int> ans(2, -1);

        int l = 0, r = nums.size()-1, mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid]>=target) r = mid - 1;
            else l = mid + 1;
        }

        if(l<nums.size() && nums[l]==target) ans[0] = l;

        l = 0, r = nums.size()-1;
        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid]>target) r = mid - 1;
            else l = mid + 1;
        }

        if(r>-1 && nums[r]==target) ans[1] = r;
        return ans;
    }
};