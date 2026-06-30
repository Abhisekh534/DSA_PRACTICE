class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>freq(n);

        for(vector<int> x : bookings){
            for(int i=x[0]-1; i<x[1]; i++){
                freq[i]+=x[2];
            }
        }

        return freq;
    }
};