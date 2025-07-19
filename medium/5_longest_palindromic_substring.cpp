class Solution {
public:
    int maxLength = 1;  // Variable to keep track of the longest palindrome length
    int start = 0;      // Variable to store the starting index of the longest palindrome
    
    // Function to expand around the center
    void expandAroundCenter(string& s, int left, int right, int n) {
        // Expand outward while the characters at left and right are equal
        while (left >= 0 && right < n && s[left] == s[right]) {
            int currentLength = right - left + 1;
            // Update maxLength and start if a longer palindrome is found
            if (currentLength > maxLength) {
                maxLength = currentLength;
                start = left;
            }
            --left;   // Move the left pointer outward
            ++right;  // Move the right pointer outward
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();
        
        // Loop through each character as a potential center for the palindrome
        for (int i = 0; i < n; ++i) {
            // Check for odd-length palindromes (single character center)
            expandAroundCenter(s, i, i, n);
            
            // Check for even-length palindromes (pair of characters center)
            expandAroundCenter(s, i, i + 1, n);
        }
        
        // Return the longest palindrome substring
        return s.substr(start, maxLength);
    }
};