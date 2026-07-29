class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>&temp, vector<int>&nums, int index){
        int n = nums.size();
        if(index==n){
            ans.push_back(temp);
            return;
        }

        int x = nums[index];
        int j = index;
        while(j<n && nums[j]==x) j++;
        solve(ans, temp, nums, j);

        temp.push_back(nums[index]);
        solve(ans, temp, nums, index+1);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans, temp, nums, 0);

        return ans;
    }
};