class Solution {
public:
    long long solve(vector<vector<int>>& questions, vector<long long>&dp, int i){
        int n = questions.size();
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        long long take = questions[i][0] + solve(questions, dp, i+questions[i][1]+1ll);
        long long skip = solve(questions, dp, i+1);

        return dp[i] = max(take, skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n, -1);

        return solve(questions, dp, 0);
    }
};