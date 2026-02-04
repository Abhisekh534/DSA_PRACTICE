class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int maxi = INT_MIN;

        for(int i=0; i<n; i++) maxi = max(maxi, nums[i]);

        vector<bool>isPrime(maxi+1, true);

        isPrime[0] = isPrime[1] = false;

        for(int i=2; i*i<=maxi; i++){
            for(int j=i*i; j<=maxi; j+=i){
                isPrime[j] = false;
            }
        }

        int sum = 0;

        for(int i=0; i<n; i++){
            if(!isPrime[nums[i]]){
                for(int j=2; j*j<nums[i]; j++){
                    if(nums[i]%j==0){
                        if(isPrime[j] && j*j*j==nums[i]) sum+=(1 + j + j*j + j*j*j);
                        else if(isPrime[j] && isPrime[nums[i]/j]) sum+=(1 + j + nums[i]/j + nums[i]);
                        else break;
                    }
                }
            }
        }

        return sum;
    }
};