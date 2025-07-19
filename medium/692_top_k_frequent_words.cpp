class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Step 1: Count the frequency of each word using a hashmap
        unordered_map<string, int> freqMap;
        for (const string& word : words) {
            freqMap[word]++;
        }

        // Step 2: Convert the hashmap to a vector of pairs (word, frequency)
        vector<pair<string, int>> wordFreqVec;
        for (const auto& entry : freqMap) {
            wordFreqVec.push_back(entry);
        }

        // Step 3: Sort the words based on frequency (desc) and lexicographical order (asc)
        sort(wordFreqVec.begin(), wordFreqVec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            // First compare by frequency in descending order
            if (a.second != b.second) {
                return a.second > b.second;
            }
            // If frequencies are the same, compare lexicographically
            return a.first < b.first;
        });

        // Step 4: Collect the top k frequent words
        vector<string> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(wordFreqVec[i].first);
        }

        return result;
    }
};