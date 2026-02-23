class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector<int>> vec(n1+1, vector<int>(n2+1, 0));

        for(int i=1; i<n1+1; i++){
            for(int j=1; j<n2+1; j++){
                if(word1[i-1]==word2[j-1]) vec[i][j] = 1 + vec[i-1][j-1];
                else vec[i][j] = max(vec[i-1][j], vec[i][j-1]);
            }
        }

        return n1+n2-2*vec[n1][n2];
    }
};