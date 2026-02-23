class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        char first = pattern[0], second = pattern[1];

        long long ans = 0;
        vector<int>fIndex;
        vector<int>sIndex;

        for(int i=0; i<text.size(); i++){
            if(text[i]==first) fIndex.push_back(i);
            else if(text[i]==second) sIndex.push_back(i); 
        }

        //agar first aur second dono same hai to sirf fIndex me jaayega sIndex me nahi due to else if
        //jo ki agar ham two pointers wale approach se kare to dikkat de sakta hai
        //but first second same wale case ko ham easy maths lagake bhi solve kar sakte hain

        if(first==second){
            long long s = fIndex.size();
            return ((s*(s+1))/2);
        } 

        char x;
        if(fIndex.size()>sIndex.size()){
            char x = second;
            text = text + second;
            sIndex.push_back(text.size());
        }else{
            char x = first;
            text = first + text;
            fIndex.insert(fIndex.begin(), -1);
        }


        int i=0, j=0;

        while(i<fIndex.size() && j<sIndex.size()){
            if(sIndex[j]>fIndex[i]){
                ans+=(sIndex.size()-j);
                i++;
            }else{
                j++;
            }
        }

        return ans;
    }
};