class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>&temp, unordered_map<int, int>&map, int count, int n){
        if(count==n){
            ans.push_back(temp);
            return;
        }

        for(auto&x : map){
            if(x.second>0){
                temp.push_back(x.first);
                x.second--;
                solve(ans, temp, map, count+1, n);
                temp.pop_back();
                x.second++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        unordered_map<int, int>map;

        for(int i=0; i<n; i++) map[nums[i]]++;

        solve(ans, temp, map, 0, n);

        return ans;
    }
};