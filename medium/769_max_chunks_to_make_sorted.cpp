class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxChunkCount = 0;  // To keep track of the number of chunks
        int maxSoFar = 0;      // To keep track of the maximum value encountered so far
        
        for (int i = 0; i < arr.size(); ++i) {
            maxSoFar = max(maxSoFar, arr[i]);
            // If the maximum value up to this point is equal to the current index,
            // we can form a chunk
            if (maxSoFar == i) {
                ++maxChunkCount;
            }
        }
        return maxChunkCount;
    }
};