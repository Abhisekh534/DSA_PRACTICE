class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==1) return matrix[0][0];

        for(int i=n-2; i>-1; i--){
            matrix[i][0] += min(matrix[i+1][0], matrix[i+1][1]);
            for(int j=1; j<n-1; j++){
                matrix[i][j] += min({matrix[i+1][j-1], matrix[i+1][j], matrix[i+1][j+1]});
            }
            matrix[i][n-1] += min(matrix[i+1][n-2], matrix[i+1][n-1]);
        }

        int mini = INT_MAX;

        for(int j=0; j<n; j++) mini = min(mini, matrix[0][j]);

        return mini;
    }
};