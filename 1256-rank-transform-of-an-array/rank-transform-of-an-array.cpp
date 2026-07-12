class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int>mp;

        vector<int>vec = arr;
        sort(vec.begin(), vec.end());

        int i = 0, j = 0;
        int rank = 1;
        while(i<n){
            while(j<n && vec[j]==vec[i]){
                mp[vec[j]] = rank;
                j++;
            }
            i = j;
            rank++;
        }

        for(int i=0; i<n; i++){
            arr[i] = mp[arr[i]];
        } 

        return arr;
    }
};