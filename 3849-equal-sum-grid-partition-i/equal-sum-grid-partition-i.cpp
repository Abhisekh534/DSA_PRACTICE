class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long>rows(m);
        for(int i=0; i<m; i++){
            long long sum = 0;
            for(int j=0; j<n; j++) sum+=(grid[i][j]);
            rows[i] = sum;
        }

        vector<long long>columns(n);

        for(int j=0; j<n; j++){
            long long sum = 0;
            for(int i=0; i<m; i++) sum+=(grid[i][j]);
            columns[j] = sum;
        }

        long long total = 0;

        for(long long x : columns){
            total+=(x);
        }

        long long pre = 0;
        long long post = total;


        for(int i=0; i<m; i++){
            pre+=(rows[i]);
            post-=(rows[i]);

            if(pre==post) return true;
        }

        pre = 0;
        post = total;


        for(int i=0; i<n; i++){
            pre+=(columns[i]);
            post-=(columns[i]);

            if(pre==post) return true;
        }

        return false;
    }
};