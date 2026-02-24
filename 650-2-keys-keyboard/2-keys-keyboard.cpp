class Solution {
public:
    int minSteps(int n) {
        vector<bool> isPrime(1001, true);
        isPrime[0] = isPrime[1] = false;

        for(int i=2; i*i<=1000; i++){
            if(isPrime[i]){
                for(int j=i*i; j<=1000; j+=i){
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;

        for(int i=0; i<1001; i++){
            if(isPrime[i]) primes.push_back(i);
        }

        int ans = 0;

        int i = 0;
        while(n!=1){
            if(n%primes[i]==0){
                n/=primes[i];
                ans+=primes[i];
            }else i++;
        }

        return ans;
    }
};