class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>>dp(n+1, vector<long long>(target+1, 0LL));

        for(int j=1; j<=k && j<=target; j++){
            dp[1][j] = 1;
        }

        for(int i=2; i<=n; i++){
            for(int j=1; j<=i*k && j<=target; j++){
                if(j-k-1<0) dp[i][j] = (dp[i][j-1] + dp[i-1][j-1])%1000000007;
                else dp[i][j] = (dp[i][j-1] - dp[i-1][j-k-1] + dp[i-1][j-1] + 1000000007)%1000000007;
            }
        }

        return (dp[n][target]);
    }
};