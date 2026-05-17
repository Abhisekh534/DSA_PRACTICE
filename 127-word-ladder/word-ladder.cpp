class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordSet;
        
        for(string word : wordList){
            wordSet.insert(word);
        }

        if(!wordSet.count(endWord)) return 0;

        queue<string>q;
        q.push(beginWord);

        int len = 1;

        while(!q.empty()){
            int qSize = q.size();
            while(qSize--){
                string word = q.front();
                q.pop();

                if(word==endWord) return len;

                for(int i=0; i<word.size(); i++){
                    for(char x='a'; x<='z'; x++){
                        string nextWord = word;
                        if(word[i]==x) continue;
                        nextWord[i]=x;

                        if(wordSet.count(nextWord)){
                            q.push(nextWord);
                            wordSet.erase(nextWord);
                        }
                    }
                }
            }
            len++;
        }

        return 0;
        
    }
};