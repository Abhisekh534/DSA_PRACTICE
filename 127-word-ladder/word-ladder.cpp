class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool>wordMap;
        
        for(string word : wordList){
            wordMap[word] = false;
        }

        if(!wordMap.count(endWord)) return 0;

        queue<string>q;
        q.push(beginWord);
        wordMap[beginWord] = true;

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

                        if(wordMap.count(nextWord) && !wordMap[nextWord]){
                            q.push(nextWord);
                            wordMap[nextWord] = true;
                        }
                    }
                }
            }
            len++;
        }

        return 0;
        
    }
};