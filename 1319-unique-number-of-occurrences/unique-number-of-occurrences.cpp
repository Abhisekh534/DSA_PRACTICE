class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int, int> um, um2;
       for(int i=0; i<arr.size(); i++){
        um[arr[i]]++;
       }

       for(auto&x : um){
        if(um2.count(x.second)) return false;
        um2[x.second]++;
       }

       return true;
    }
};