class Solution {
public:
    int numSquares(int n) {
       
        vector<int> dp(n + 1, INT_MAX);
        
        
        dp[0] = 0;

        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                int square = j * j;
                dp[i] = min(dp[i], dp[i - square] + 1);
            }
        }

        
        return dp[n];
    }
};



    
    /*int solveusingmemoisation(int n, vector<int>& dp) {
        if (n == 0) {
            return 0; 
        }
        if (dp[n] != -1) {
            return dp[n]; 
        }
        
        int minCount = INT_MAX;
        
        for (int i = 1; i * i <= n; ++i) {
            int square = i * i;
            
            minCount = min(minCount, 1 + solveusingmemoisation(n - square, dp));
        }
        
        dp[n] = minCount; 
        return dp[n];
    }

    int numSquares(int n) {
        
        vector<int> dp(n + 1, -1);
        return solveusingmemoisation(n, dp);
    }
};



int solveusingrecursion(int &n){
       if (n == 0) {
            return 0;
        }
        
        int minCount = INT_MAX;
        
        
        for (int i = 1; i * i <= n; ++i) {
            int square = i * i;
            // Recur for the reduced number
            minCount = min(minCount, 1 + numSquares(n - square));
        }
        
        return minCount;
}*/