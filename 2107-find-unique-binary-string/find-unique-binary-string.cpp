class Solution {
public:
    void solve(vector<string>&ans, string&temp, int n, int i){
        if(i==n){
            ans.push_back(temp);
            return;
        }

        temp.push_back('0');
        solve(ans, temp, n, i+1);
        temp.pop_back();
        temp.push_back('1');
        solve(ans, temp, n, i+1);
        temp.pop_back();
    }
        
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();

        vector<string>ans;
        string temp="";
        solve(ans, temp, n, 0);

        for(string x : ans){
            bool found = false;
            for(string y : nums){
                if(x==y){
                    found = true;
                    break;
                }
            }
            if(!found) return x;
        }

        return "";
    }
};