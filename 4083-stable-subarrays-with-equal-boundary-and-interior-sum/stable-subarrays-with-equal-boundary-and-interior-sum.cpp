class Solution {
public:
    struct pair_hash {
        template <class T1, class T2>
        ssize_t operator () (const pair<T1, T2>& p) const {
            auto h1 = hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            // Combine the two hashes securely
            return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
        }
    };

    long long countStableSubarrays(vector<int>& capacity) {

        int n = capacity.size();
        vector<long long>prefixSum(n);

        prefixSum[0] = 0;
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + capacity[i-1];
        }

        unordered_map<pair<long long, int>, int, pair_hash>mp; //prefixSum[i] + capacity[i] -> count of such occurences
        //on template of custom pair_hash struct 

        long long ans = 0;

        for(int i=1; i<n; i++){
            int curr = capacity[i];
            if(mp.find({prefixSum[i] - 2*curr, curr})!=mp.end()){
                ans+=mp[{prefixSum[i] - 2*curr, curr}];
            }
            mp[{prefixSum[i-1], capacity[i-1]}]++;
            //directly current wala store mat karo
            //har iteration mein ek pehele wala store karo to avoid subarray length<3
        }

        return ans;
    }
};