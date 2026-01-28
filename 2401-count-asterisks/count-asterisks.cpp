class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;

        int i=0;
        while(i<s.size()){
            if(s[i]=='|'){
                i++;
                while(i<s.size() && s[i]!='|') i++;
            }else{
                if(s[i]=='*') count++;
            }
            i++;
        }

        return count;
    }
};