class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string>dSet;

        for(string x : deadends) dSet.insert(x);

        if(target=="0000") return 0;
        if(dSet.find("0000")!=dSet.end()) return -1;

        vector<int>visited(10000, false);

        int turns = 0;
        
        queue<string>q;
        q.push("0000");
        visited[0] = true;

        int qSize;

        while(!q.empty()){
            qSize = q.size();

            while(qSize--){

                string pattern = q.front();
                if(pattern==target) return turns;
                q.pop();

                for(int i=0; i<4; i++){
                    string possible1 = pattern;
                    if(possible1[i]<'9') possible1[i]++;
                    else possible1[i] = '0';

                    string possible2 = pattern;
                    if(possible2[i]>'0') possible2[i]--;
                    else possible2[i] = '9';

                    if(!visited[stoi(possible1)] && dSet.find(possible1)==dSet.end()){
                        q.push(possible1);
                        visited[stoi(possible1)] = true;
                    }

                    if(!visited[stoi(possible2)] && dSet.find(possible2)==dSet.end()){
                        q.push(possible2);
                        visited[stoi(possible2)] = true;
                    }
                }
            }
            turns++;
        }

        return -1;
    }
};