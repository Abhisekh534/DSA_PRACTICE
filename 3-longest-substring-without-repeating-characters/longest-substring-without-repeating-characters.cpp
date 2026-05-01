class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>map;
        int i=0, j=0;

        int maxi = 0;

        while(j<s.size()){
            map[s[j]]++;
            if(map[s[j]]==2){
                while(map[s[i]]!=2){
                    map[s[i]]--;
                    i++;
                }
                map[s[i]]--;
                i++;
            }

            maxi = max(maxi, j-i+1);
            j++;
        }

        return maxi;
    }
};