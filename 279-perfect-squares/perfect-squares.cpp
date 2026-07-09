class Solution {
public:
    int numSquares(int n) {
        //bottom up
        
        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0; //prevents overflow when i is perfect square and 'square' = i
        
        for(int i=1; i<=n; i++){

            int mini = INT_MAX;
            for(int j=1; j*j<=i; j++){
                mini = min(mini, 1+dp[i-j*j]);
            }
            dp[i] = mini;

        }

        return dp[n];
    }
};