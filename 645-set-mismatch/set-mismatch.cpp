class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int>freq(n+1);
        for(int x : nums) freq[x]++;

        int x, y;
        for(int i=1; i<=n; i++){
            if(freq[i]==2) x = i;
            else if(freq[i]==0) y = i;
        }

        return {x, y};
    }
};