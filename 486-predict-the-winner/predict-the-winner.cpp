class Solution {
public:
    bool solve(vector<int>&nums, int a, int b, int i, int j, bool isFirst){
        if(i>j){
            if(a>=b) return true;
            return false;
        }

        if(isFirst){
            return solve(nums, a+nums[i], b, i+1, j, false) || solve(nums, a+nums[j], b, i, j-1, false);
        }else{
            return solve(nums, a, b+nums[i], i+1, j, true) && solve(nums, a, b+nums[j], i, j-1, true);
        }

    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, 0, 0, n-1, true);
    }
};