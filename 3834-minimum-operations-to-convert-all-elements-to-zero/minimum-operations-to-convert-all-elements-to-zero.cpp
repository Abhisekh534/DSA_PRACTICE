class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        stack<int>st;

        int count = 0;

        for(int i=0; i<n; i++){
            while(!st.empty() && st.top()>nums[i]){
                st.pop();
                count++;
            }
            if(nums[i]!=0 && (st.empty() || st.top()<nums[i])) st.push(nums[i]);
        }

        return count + st.size();
    }
};