class Solution {
public:
    int solve(int n, vector<int>& days, vector<int>& cost, int index, vector<int>& dp) {
        // Base case
        if (index >= n) {
            return 0;
        }

        // Check if already computed
        if (dp[index] != -1) {
            return dp[index];
        }

        // Option 1: Buy a 1-day pass
        int option1 = cost[0] + solve(n, days, cost, index + 1, dp);

        // Option 2: Buy a 7-day pass
        int i;
        for (i = index; i < n && days[i] < days[index] + 7; i++);
        int option2 = cost[1] + solve(n, days, cost, i, dp);

        // Option 3: Buy a 30-day pass
        for (i = index; i < n && days[i] < days[index] + 30; i++);
        int option3 = cost[2] + solve(n, days, cost, i, dp);

        // Store the result in dp
        dp[index] = min(option1, min(option2, option3));
        return dp[index];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1); // Use dp of size n
        return solve(n, days, costs, 0, dp);
    }
};
