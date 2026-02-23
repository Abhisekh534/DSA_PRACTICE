class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        char first = pattern[0], second = pattern[1];

        int fCount = 0, sCount = 0;
        for(int i=0; i<text.size(); i++){
            if(text[i]==first) fCount++;
            if(text[i]==second) sCount++;
        }

        char x;
        if(first==second){
            return ((long long)fCount*(fCount+1))/2;
        }
        else if(fCount>sCount){
            char x = second;
            text = text + second;
        }else{
            char x = first;
            text = first + text;
        }
        long long ans = 0;
        vector<int>fIndex;
        vector<int>sIndex;

        for(int i=0; i<text.size(); i++){
            if(text[i]==first) fIndex.push_back(i);
            if(text[i]==second) sIndex.push_back(i); 
            //agar first second same hua to index overlap bhi ho sakte hain isliye if else ki jagah if if use kiya hai
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