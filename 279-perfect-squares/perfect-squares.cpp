class Solution {
public:
    int solve(vector<int>&dp, vector<int>&squares, int n){
        if(n==0) return 0;
        if(n<0) return INT_MAX;

        if(dp[n]!=-1) return dp[n];

        int mini = INT_MAX;

        for(int square : squares){
            int ans = solve(dp, squares, n-square);

            if(ans!=INT_MAX) mini = min(mini, 1+ans);
        }

        return dp[n] = mini;
    }

    int numSquares(int n) {
        vector<int>squares;

        for(int i=1; i*i<=n; i++){
            squares.push_back(i*i);
        }

        vector<int>dp(n+1, -1);
        return solve(dp, squares, n);
    }
};