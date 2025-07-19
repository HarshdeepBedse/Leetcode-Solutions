class Solution {
public:
    int convert(string& time) {
        int hr = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3, 2));
        return hr * 60 + min;
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;
        for (auto& time : timePoints) {
            mins.push_back(convert(time));
        }

        sort(mins.begin(), mins.end());

        int ans = INT_MAX;
        for (int i = 1; i < mins.size(); ++i) {
            ans = min(ans, mins[i] - mins[i - 1]);
        }

        // Check the circular difference
        int circular_diff = mins[0] + 1440 - mins.back();
        ans = min(ans, circular_diff);

        return ans;
    }
};