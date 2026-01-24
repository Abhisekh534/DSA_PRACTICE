class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }
        int l = 1, h = maxi;
        int mid = l + (h-l)/2;

        while(l<h){
            int sum = 0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]%mid==0) sum+=(nums[i]/mid);
                else sum+=(nums[i]/mid)+1;
            }

            if(sum>threshold) l = mid+1;
            else h=mid;

            mid = l + (h-l)/2;
        }

        return h;
    }
};