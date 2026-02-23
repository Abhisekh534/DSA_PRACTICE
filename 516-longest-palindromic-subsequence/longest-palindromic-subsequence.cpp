class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>>vec(n+1, vector<int>(n+1, 0));

        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(s[i-1]==s[n-j]) vec[i][j] = 1 + vec[i-1][j-1];
                else vec[i][j] = max(vec[i-1][j], vec[i][j-1]);
            }
        }

        return vec[n][n];
    }
};