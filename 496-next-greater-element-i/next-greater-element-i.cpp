class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>map;
        for(int i=0; i<nums1.size(); i++) map[nums1[i]] = i;

        vector<int>ans(nums1.size(), -1);
        //decreasing monotonic stack
        stack<int>st;

        for(int i=0; i<nums2.size(); i++){
            while(!st.empty() && nums2[i]>=st.top()){
                if(map.find(st.top())!=map.end()) ans[map[st.top()]] = nums2[i];
                st.pop();
            }

            st.push(nums2[i]);
        } 

        return ans;
    }
};