class Solution {
public:
    int numSquares(int n) {
        //bottom up
        vector<int>squares;

        for(int i=1; i*i<=n; i++){
            squares.push_back(i*i);
        }

        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0; //prevents overflow when i is perfect square and 'square' = i
        dp[1] = 1;
        
        for(int i=2; i<=n; i++){

            int mini = INT_MAX;
            for(int square : squares){
                if(i-square>=0){
                    mini = min(mini, 1+dp[i-square]);
                }
            }
            dp[i] = mini;

        }

        return dp[n];
    }
};