class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];

        vector<int>tabu(n, 0);

        tabu[0] = nums[0];
        tabu[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; i++){
            tabu[i] = max(tabu[i-2]+nums[i], tabu[i-1]);
        }

        return tabu[n-1];
    }
};