class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>mH;

        for(int x : nums) mH.push(x);

        for(int i=0; i<k-1; i++) mH.pop();

        return mH.top();
    }
};