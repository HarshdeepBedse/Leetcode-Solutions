class Solution {
public:
int solveusingdp(int n,vector<int>&dp){
    if(n==0 || n==1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=solveusingdp(n-1,dp)+solveusingdp(n-2,dp);
    return dp[n];
}

    int fib(int n) {
//step 1 create a dp array
 vector<int>dp(n+1,-1); 
 int ans=solveusingdp(n,dp);
 return ans;       
    }
};