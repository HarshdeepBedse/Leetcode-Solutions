class Solution {
public:
int expand(string s,int i,int j){
    int count=0;
    while(i>=0 && j<s.length()&& s[i]==s[j]){
        count++;
        i--;
        j++;
    }
    return count;
}
    int countSubstrings(string s) {
        int totalcount=0;
        for (int center=0;center<s.length();center++){
            int oddans=expand(s,center,center);
            int evenans=expand(s,center,center+1);
            totalcount+=oddans+evenans;
        }
        return totalcount;
    }
};