class Solution {
public:
    string decodeString(string s) {
        int i = 0; // Initialize the index
        return decodeStringHelper(s, i);
    }

private:
    string decodeStringHelper(string& s, int& i) {
        string result;
        while (i < s.length() && s[i] != ']') {
            if (isdigit(s[i])) {
                int k = 0;
                while (i < s.length() && isdigit(s[i]))
                    k = k * 10 + (s[i++] - '0');

                // Skip the opening bracket '['
                i++;

                // Recurse to decode the inner string
                string inner = decodeStringHelper(s, i);

                // Append the decoded inner string k times
                while (k-- > 0)
                    result += inner;
            } else {
                // Append non-digit characters directly
                result += s[i++];
            }
        }

        // Skip the closing bracket ']'
        i++;

        return result;
    }
};