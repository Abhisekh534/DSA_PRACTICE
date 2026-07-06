class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int>mp;

        for(int x : nums) mp[x]++;

        int ans = 0;
        for(auto& x : mp){
            if(x.second<2) return -1;
            ans+=(x.second/3);
            if(x.second%3!=0) ans+=1;
        }

        return ans;
    }
};