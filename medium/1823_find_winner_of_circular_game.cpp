class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()>1){
            for(int i=1;i<k;i++){
                int player= q.front();
                q.pop();
                q.push(player);
            }
            q.pop();
        }
        return q.front();
    }
};