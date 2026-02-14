class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int, int> um;
       for(int i=0; i<arr.size(); i++){
        um[arr[i]]++;
       }
       unordered_set<int> setA;

       for(auto&x : um){
        setA.insert(x.second);
       }
       return(setA.size()==um.size());
    }
};