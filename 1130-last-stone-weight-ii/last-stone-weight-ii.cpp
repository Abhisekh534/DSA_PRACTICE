class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;

        for(int i=0; i<stones.size(); i++) sum+=stones[i];

        int target = sum/2;

        vector<int>dp(target+1, false);
        dp[0] = true;

        for(int stone : stones){
            for(int j=target; j>=stone; j--){
                dp[j] = dp[j] || dp[j - stone];
            }
        }

        for(int i=target; i>-1; i--){
            if(dp[i]) return sum - 2*i;
        }

        return 0;
    }
};