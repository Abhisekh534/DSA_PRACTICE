class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        
        queue<int>q;

        for(int i=1; i<=9; i++) q.push(i);
        
        while(!q.empty()){
            int number = q.front();
            q.pop();

            if(number>high) continue;

            if(number>=low) ans.push_back(number);

            if(number%10==9) continue;

            number*=10;
            number+=(((number/10)%10)+1);

            q.push(number);
        }

        return ans;
    }
};