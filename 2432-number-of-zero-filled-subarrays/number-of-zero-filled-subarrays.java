class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long totalCount = 0;
        int count0 = 0;

        for(int i=0; i<nums.length; i++){
            if(nums[i]==0){
                count0++;
                totalCount+=count0;
            }else count0 = 0;
        }

        return totalCount;
    }
}