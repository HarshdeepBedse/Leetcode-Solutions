class Solution {
public:
    int solve(vector<int>& piles, int i, int M, int alice, vector<vector<vector<int>>>& dp) {
        if (i == piles.size()) return 0; // Base case: no piles left

        if (dp[i][M][alice] != -1) return dp[i][M][alice]; // Return cached result

        int ans = alice ? INT_MIN : INT_MAX; // Maximize for Alice, minimize for Bob
        int total = 0;

        for (int X = 1; X <= 2 * M; ++X) {
            if (i + X - 1 >= piles.size()) break; // Ensure within bounds
            total += piles[i + X - 1];

            if (alice) { // Alice's turn
                ans = max(ans, total + solve(piles, i + X, max(M, X), !alice, dp));
            } else { // Bob's turn
                ans = min(ans, solve(piles, i + X, max(M, X), !alice, dp));
            }
        }

        dp[i][M][alice] = ans; // Cache result
        return ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(2, -1))); // 3D DP table
        return solve(piles, 0, 1, true, dp); // Start with i=0, M=1, Alice's turn
    }
};
/*class Solution {
public:
    int solve(vector<int>& piles, int i, int M, int alice) {
        if (i == piles.size()) return 0;

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;

        for (int X = 1; X <= 2 * M; ++X) {
            if (i + X - 1 >= piles.size()) break;
            total += piles[i + X - 1];

            if (alice)
                ans = max(ans, total + solve(piles, i + X, max(X, M), !alice));
            else
                ans = min(ans, solve(piles, i + X, max(X, M), !alice));
        }
        return ans;
    }

    int stoneGameII(vector<int>& piles) {
        return solve(piles, 0, 1, true);
    }
};
*/