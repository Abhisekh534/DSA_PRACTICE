class Solution {
public:
    int findNthDigit(int n) {
        if(n<10) return n;
       
        long long i=0;
        while(n>9LL*pow(10, i)*(i+1)){
            n = n - 9*pow(10, i)*(i+1);
            i++;
        }

        long long start = pow(10, i);

        long long num = start + (n-1)/(i+1);
        int y = (n-1)%(i+1);

        string z = to_string(num);
        return z[y] - '0';
    }
};