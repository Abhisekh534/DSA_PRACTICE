class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>map;
        //to store how many times we reached a sum X;
        //like if we reached the sum of 5 3 times, then map[5] = 3;

        map[0]++;//base case 
        
        //(if subarray starts from the first element, we have to consider that the sum reached before the first element is 0)

        int count = 0;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            
            sum+=nums[i];
            if(map.find(sum - k)!=map.end()) count+=map[sum-k];

            map[sum]++;
        }

        return count;
    }
};