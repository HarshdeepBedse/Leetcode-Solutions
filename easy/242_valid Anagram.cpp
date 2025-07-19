class Solution {
public:
    bool isAnagram(string s, string t) {
         if (s.length() != t.length()) return false;
        unordered_map<char,int>freq1;
        unordered_map<char,int>freq2;
        for(auto x:s){
            freq1[x]++;
        }
        for(auto y:t){
            freq2[y]++;
        }
          return freq1 == freq2;


    }
};