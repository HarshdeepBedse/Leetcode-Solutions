class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> frequency; // Map to store node frequencies
        
        // Count frequency of each node
        for (auto& edge : edges) {
            frequency[edge[0]]++; // Increment frequency for the first node in the edge
            frequency[edge[1]]++; // Increment frequency for the second node in the edge
        }
        
        // Find the node with frequency equal to n - 1
        for (auto& [node, freq] : frequency) {
            if (freq == edges.size()) { // Center node will appear in all edges
                return node;
            }
        }
        
        return -1; 
    }
};