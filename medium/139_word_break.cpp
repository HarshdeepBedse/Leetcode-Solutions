class Solution {
public:
int f(int index, string& s, unordered_map<string, bool>& dict, vector<int>& dp) {
        // base condition
        if (index >= s.size()) return 1;

        // already computed
        if (dp[index] != -1) return dp[index]; 
        
        // Try all cuts
        string curr = "";
        for (int i = index; i < s.size(); i++) {
            curr.push_back(s[i]);
            // if curr string present in dict, check for remaining part
            if(dict[curr] && f(i+1, s, dict, dp))
                return dp[index] = 1;
        }
        // split not possible
        return dp[index] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // store dictionary words in map
        unordered_map<string, bool> dict;
        for (auto& word : wordDict) 
            dict[word] = true;

        vector<int> dp(s.size(),-1);    // memo
        // Write recursion function to check all cuts
        // index, string, map , dp
        return f(0, s, dict, dp);
    }
};