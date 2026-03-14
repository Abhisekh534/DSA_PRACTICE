class Solution {
public:
    int solve(vector<vector<char>>&matrix, vector<vector<int>>&dp, int i, int j, int&maxi){
        if(i==0){
            if(matrix[0][j]=='1') return 1; 
            else return 0;
        }
        if(j==0){
            if(matrix[i][0]=='1') return 1; 
            else return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(matrix[i][j]=='0') return dp[i][j] = 0;
        else{
            return dp[i][j] = 1 + min({solve(matrix, dp, i, j-1, maxi), solve(matrix, dp, i-1, j, maxi), solve(matrix, dp, i-1, j-1, maxi)});
        }

    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));

        int maxi = 0;
        for(int i=m-1; i>-1; i--){
            for(int j=n-1; j>-1; j--){
                maxi = max(maxi, solve(matrix, dp, i, j, maxi));
            }
        }

        return maxi*maxi;
        
    }
};