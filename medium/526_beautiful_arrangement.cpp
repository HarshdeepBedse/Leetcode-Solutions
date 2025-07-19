class Solution {
public:
void countarrangementhelper(vector<int>&v,int&n,int&ans,int currentnum){
    if (currentnum==n+1){
        ++ans;
        return;
    }
    for(int i=1;i<=n;i++){
        if(v[i]==0 && ( currentnum%i==0 || i%currentnum==0)){
            v[i]=currentnum;
            countarrangementhelper(v,n,ans,currentnum+1);
            v[i]=0;
        }
    }
}
int countArrangement(int n) {
        vector<int>v(n+1);
        int ans=0;
        countarrangementhelper(v,n,ans,1);
        return ans;
    }
};