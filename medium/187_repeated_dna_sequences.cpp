
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;  // Set to store substrings we've already seen
        unordered_set<string> repeated;  // Set to store repeated substrings
        vector<string> result;  // Vector to store final result

        // If the string length is less than 10, return an empty result
        if (s.length() < 10) {
            return result;
        }

        // Iterate over the string and extract 10-letter substrings
        for (int i = 0; i <= s.length() - 10; ++i) {
            string substring = s.substr(i, 10);  // Get the current 10-letter substring
            // If the substring is already in 'seen', add it to 'repeated'
            if (seen.count(substring)) {
                repeated.insert(substring);
            } else {
                seen.insert(substring);
            }
        }

        // Convert the 'repeated' set to a vector to return the result
        for (const string& str : repeated) {
            result.push_back(str);
        }

        return result;
    }
};