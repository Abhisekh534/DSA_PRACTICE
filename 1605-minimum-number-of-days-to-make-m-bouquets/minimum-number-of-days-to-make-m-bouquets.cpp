class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n/m<k) return -1;

        int l = INT_MAX;
        int e = INT_MIN;

        for(int x : bloomDay){
            l = min(x, l);
            e = max(x, e);
        }

        int mid;

        while(l<e){
            mid = l + (e-l)/2;

            int countB = 0;
            int nk = 0;
            int i = 0;
            while(i<n){
                if(mid<bloomDay[i]) nk = 0;
                else nk++;

                if(nk==k){
                    countB++;
                    nk = 0;
                }
                i++;
            }

            if(countB<m) l = mid+1;
            else e = mid;
        }

        return l;
    }
};