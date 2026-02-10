class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        if(obstacleGrid[n-1][m-1]==1) return 0;
        
        vector<vector<long long>>paths(n, vector<long long>(m, 0LL));

        paths[n-1][m-1] = 1LL;

        for(int i=n-2; i>-1; i--){
            if(obstacleGrid[i][m-1]==1) paths[i][m-1]=0;
            else paths[i][m-1]=paths[i+1][m-1];
        }

        for(int j=m-2; j>-1; j--){
            if(obstacleGrid[n-1][j]==1) paths[n-1][j]=0;
            else paths[n-1][j]=paths[n-1][j+1];
        }

        if(paths[0][0]!=0) return paths[0][0];

        for(int i=n-2; i>-1; i--){
            for(int j=m-2; j>-1; j--){
                if(obstacleGrid[i][j]==1) paths[i][j]=0;
                else paths[i][j] = paths[i+1][j] + paths[i][j+1];
            }
        }

        return paths[0][0];
    }
};