class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        vector<bool> visited(n+1, false); 

        q.push(n);
        visited[n] = true;

        int steps = 0;

        while(!q.empty()){
            int size = q.size();
            steps++;

            for(int i=0; i<size; i++){
                int curr = q.front();
                q.pop();

                for(int j=1; j*j<=curr; j++){
                    int next = curr - j*j;
                    if(next==0) return steps;

                    if(!visited[next]){
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        return -1;
    }
};