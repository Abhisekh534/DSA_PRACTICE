class Solution {
public:
    void solve(vector<int>&ans, int low, int high, int temp){
        if(temp>high) return;

        if(temp>=low) ans.push_back(temp);

        if(temp%10==9) return;

        temp*=10;
        temp+=(((temp/10)%10)+1);

        solve(ans, low, high, temp);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1; i<=9; i++){
            solve(ans, low, high, i);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};