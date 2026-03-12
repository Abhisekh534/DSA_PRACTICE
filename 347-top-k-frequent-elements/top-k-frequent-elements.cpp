class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>um;

        for(int x : nums) um[x]++;

        priority_queue<pair<int, int>>mH;

        for(auto& x: um){
            mH.push({x.second, x.first});
        }

        vector<int>ans;

        for(int i=0; i<k; i++){
            ans.push_back(mH.top().second);
            mH.pop();
        }

        return ans;
    }
};