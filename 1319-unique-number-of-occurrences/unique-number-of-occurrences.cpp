class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int, int> um, um2;
       for(int i=0; i<arr.size(); i++){
        um[arr[i]]++;
       }

       for(auto&x : um){
        um2[x.second]++;
       }

       for(auto&x : um2){
        if(x.second>1) return false;
       }

       return true;
    }
};