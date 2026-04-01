class Solution {
public:
    const int MOD = 1e9+7;

    int solve(vector<vector<long long>>& dp, int k, int i, int j){

        if(i == 0) return (j == 0);

        if(j > i * k) return 0;
        if(j < i) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(j - k - 1 < 0){
            return dp[i][j] = (
                solve(dp, k, i, j-1) + 
                solve(dp, k, i-1, j-1)
            ) % MOD;
        }
        else{
            long long a = solve(dp, k, i, j-1);
            long long b = solve(dp, k, i-1, j-k-1);
            long long c = solve(dp, k, i-1, j-1);

            long long res = (a - b) % MOD;
            if(res < 0) res += MOD;

            res = (res + c) % MOD;

            return dp[i][j] = res;
        }
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n+1, vector<long long>(target+1, -1));
        return solve(dp, k, n, target);
    }
};