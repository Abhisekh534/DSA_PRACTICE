class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>map;
        int i=0, j=0;

        int maxi = 0;

        while(j<s.size()){
            if(map.find(s[j])!=map.end()) i = max(i, map[s[j]]+1);
            
            map[s[j]]=j;

            maxi = max(j-i+1, maxi);
            
            j++;
        }

        return maxi;
    }
};