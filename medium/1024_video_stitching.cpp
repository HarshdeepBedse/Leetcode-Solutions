

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        // Sort clips by starting time, then by end time
        sort(clips.begin(), clips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        
        int current_end = 0;  // Current coverage end
        int next_end = 0;     // Farthest point we can reach
        int count = 0;        // Number of clips used
        int i = 0;
        
        // Iterate through the clips
        while (i < clips.size() && current_end < time) {
            // Update the next_end for all clips starting before or at current_end
            while (i < clips.size() && clips[i][0] <= current_end) {
                next_end = max(next_end, clips[i][1]);
                i++;
            }
            
            // If we can't extend the coverage, return -1
            if (current_end == next_end) {
                return -1;
            }
            
            // Move current_end to the next_end and increase the count
            current_end = next_end;
            count++;
        }
        
        // If current_end is at least 'time', return the number of clips
        return current_end >= time ? count : -1;
    }
};