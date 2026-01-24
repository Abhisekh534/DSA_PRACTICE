class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>>st;
        int maxArea = 0;

        for(int i=0; i<heights.size(); i++){
            int leftbound = i;//the last element it pops is its leftbound
            //if it does not pop anything its index is its leftbound
            while(!st.empty() && st.top().second > heights[i]){
                maxArea = max(maxArea, (i-st.top().first)*st.top().second);
                leftbound = st.top().first;
                st.pop();
            }
            st.push({leftbound, heights[i]});
        }

        //second of pair at the top of the stack will not be the right bound for the bars that remain in the stack at last because it stores the leftbound for the top element not necessarily its own index
        
        int rightbound = heights.size();
        while(!st.empty()){
            maxArea = max(maxArea, (rightbound - st.top().first) * st.top().second);
            st.pop();
        }

        return maxArea;
    }
};