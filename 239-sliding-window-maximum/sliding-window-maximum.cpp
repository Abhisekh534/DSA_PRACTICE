class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int>res;
        res.reserve(n-k+1);

        deque<int>dq;
        //deque me elements ki jagah unke element daalta hu taaki window shift karde samay deque ke left se nikalna hai ya nahi vo judge kar paaye

        //setting up the first window in deque
        for(int i=0; i<k; i++){

            while(!dq.empty() && nums[i]>=nums[dq.back()]) dq.pop_back();

            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]);

        for(int i=k; i<n; i++){
            if(!dq.empty() && dq.front()<=i-k) dq.pop_front();

            while(!dq.empty() && nums[i]>=nums[dq.back()]) dq.pop_back();

            dq.push_back(i);

            res.push_back(nums[dq.front()]);
        }

        return res;
    }
};