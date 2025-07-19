class Solution {
public:
    int solve(vector<int>& sv, int i, vector<int>& dp) {
        if (i == sv.size()) return 0; // Base case: no stones left to pick

        if (dp[i] != INT_MIN) return dp[i]; // Return cached result if available

        int ans = INT_MIN;
        int total = 0;

        for (int X = 1; X <= 3; ++X) { 
            if (i + X - 1 >= sv.size()) break; 
            total += sv[i + X - 1];
            ans = max(ans, total - solve(sv, i + X, dp)); 
        }

        return dp[i] = ans; 
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN); 

        int ans = solve(stoneValue, 0, dp); 

        
        if (ans > 0) return "Alice";
        if (ans < 0) return "Bob";
        return "Tie";
    }
};