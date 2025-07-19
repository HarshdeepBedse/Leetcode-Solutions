#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freqa;
        unordered_map<char, int> freqb;

        // Count frequencies of characters in ransomNote
        for (char ch : ransomNote) {
            freqa[ch]++;
        }

        // Count frequencies of characters in magazine
        for (char ch : magazine) {
            freqb[ch]++;
        }

        // Check if magazine can cover the ransomNote
        for (auto& entry : freqa) {
            if (freqb[entry.first] < entry.second) {
                return false;
            }
        }

        return true;
    }
};