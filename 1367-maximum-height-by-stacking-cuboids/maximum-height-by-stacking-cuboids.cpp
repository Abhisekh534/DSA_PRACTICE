class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();

        for(int i=0; i<n; i++){
            sort(cuboids[i].begin(), cuboids[i].end());
        }

        sort(cuboids.begin(), cuboids.end());

        vector<int>dp(n);

        for(int i=0; i<n; i++){
            dp[i] = cuboids[i][2]; //height
        }

        int maxi = cuboids[n-1][2];
        for(int i=n-2; i>-1; i--){

            for(int j=i+1; j<n; j++){
                if(cuboids[i][0]<=cuboids[j][0] && cuboids[i][1]<=cuboids[j][1] && cuboids[i][2]<=cuboids[j][2]){
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                    //comparing dp[i](best possible solution till now) with dp[j](best height stack for jth cube) + height of the current one
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};