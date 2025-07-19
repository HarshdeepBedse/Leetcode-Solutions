class Solution {
public:
    vector<vector<int>> memo;
    
    int dp(int i, int t, vector<int>& arr) {
        // Base case: if index is out of bounds
        if (i >= arr.size()) return 0;
        
        // Check if already computed
        if (memo[i][t] != -1) return memo[i][t];
        
        // Option 1: Do not take the current task
        int not_taken = dp(i + 1, t, arr);
        
        // Option 2: Take the current task
        int taken = arr[i] * t + dp(i + 1, t + 1, arr);
        
        // Memoize and return the result
        return memo[i][t] = max(taken, not_taken);
    }
    
    int maxSatisfaction(vector<int>& arr) {
        // Sort the satisfaction array
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        
        // Initialize the memoization table
        memo.resize(n, vector<int>(n + 1, -1));
        
        // Start the DP function
        return dp(0, 1, arr); // Start with time t = 1
    }
};