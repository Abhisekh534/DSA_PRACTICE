class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>sett;

        for(int x : nums){
            if(sett.find(x)!=sett.end()) return true;
            sett.insert(x);
        }

        return false;
    }
};