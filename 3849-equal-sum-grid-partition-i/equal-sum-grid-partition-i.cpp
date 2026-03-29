class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                total+=(grid[i][j]);
            }
        }

        if(total%2 == 1) return false;

        long long pre = 0;
        long long post = total;


        for(int i=0; i<m; i++){
            long long rowSum = 0;
            for(int j=0; j<n; j++) rowSum+=(grid[i][j]);

            pre+=rowSum;
            post-=rowSum;

            if(pre==post) return true;
        }

        pre = 0;
        post = total;


        for(int j=0; j<n; j++){
            long long columnSum = 0;
            for(int i=0; i<m; i++) columnSum+=(grid[i][j]);

            pre+=columnSum;
            post-=columnSum;

            if(pre==post) return true;
        }

        return false;
    }
};