

class Solution {
public:
    bool canConstruct(string s, int k) {
        // If the string length is less than k, it's impossible to create k palindromes
        if (s.length() < k) {
            return false;
        }

        // Count the frequency of each character
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Count the number of characters with odd frequencies
        int oddCount = 0;
        for (int count : freq) {
            if (count % 2 != 0) {
                oddCount++;
            }
        }

        // Check if the number of odd counts is greater than k
        return oddCount <= k;
    }
};