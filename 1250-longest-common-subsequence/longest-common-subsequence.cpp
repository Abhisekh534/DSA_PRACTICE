class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>vec(n+1, vector<int>(m+1, 0));

        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(text1[i-1]==text2[j-1]) vec[i][j] = 1 + vec[i-1][j-1];
                else vec[i][j] = max(vec[i][j-1], vec[i-1][j]);
            }
        }

        return vec[n][m];
    }
};