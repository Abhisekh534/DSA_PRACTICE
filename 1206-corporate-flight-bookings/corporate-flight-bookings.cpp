class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>p(n);

        for(vector<int> x : bookings){
            p[x[0]-1]+=x[2];
            if(x[1]!=n) p[x[1]]-=x[2];
        }

        for(int i=1; i<n; i++) p[i]+=p[i-1];

        return p;
    }
};