class Solution {
public:
static string str;
static bool comp(char ch1,char ch2){
    return ( str.find(ch1)<str.find(ch2));
}
    string customSortString(string order, string s) {
        str=order;
        sort(s.begin(),s.end(),comp);
        return s;
    }
};
string Solution::str;