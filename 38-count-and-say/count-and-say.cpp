class Solution {
public:
    string solve(string s){
        string x = "";

        int i=0, j = 0;
        while(j<s.size() && s[i]==s[j]){
            j++;
            if(s[j]!=s[i]){
                x+= (j-i + '0');
                x+= s[i];
                i=j;
            }
        }
        
        return x;
        
    }
    
    string countAndSay(int n) {
        if(n==1) return "1";

        string s = "1";
        for(int i=1; i<n; i++){
            s = solve(s);
        }

        return s;
    }
};