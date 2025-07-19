class Solution {
public:
bool isvowel(char ch){
    return ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U'; 
}
    string reverseVowels(string s) {
        int l=0,h=s.size()-1;
        while(l<h){
            if(isvowel(s[l])&&isvowel(s[h])){
                swap(s[l],s[h]);
                l++;
                h--;
            }
            else if (!isvowel(s[l])){
                l++;
            }
            else{
                h--;
            }
        }
        return s;
    }
};