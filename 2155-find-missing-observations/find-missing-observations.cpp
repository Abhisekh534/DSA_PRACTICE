class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int mSum = 0;
        for(int x : rolls) mSum+=x;

        int total = mean*(m+n);

        vector<int>ans;

        if((total-mSum)>6*n || (total-mSum)<n) return ans;

        int x = (total-mSum)/n;

        int b = (total-mSum)%n;
        int a = n-b;

        for(int i=0; i<a; i++) ans.push_back(x);
        for(int i=0; i<b; i++) ans.push_back(x+1);

        return ans;
    }
};