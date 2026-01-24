class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        string x = "";
        for(int i=0; i<s.size(); i++){
            if(!st.empty() && st.top()==s[i]){
                st.pop();
                x.pop_back();
            }
            else{
                st.push(s[i]);
                x.push_back(s[i]);
            }
        }

        return x;
    }
};