class Solution {
public:
    string removeDuplicates(string s) {
        string x = "";
        for(int i=0; i<s.size(); i++){
            if(!x.empty() && x.back()==s[i]) x.pop_back();
            else x.push_back(s[i]);
        }

        return x;
    }
};