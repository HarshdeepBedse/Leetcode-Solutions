class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();  // Number of nodes in the graph
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V, 0);

        // Reverse the graph and calculate indegrees
        for (int i = 0; i < V; i++) {
            for (auto it : graph[i]) {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNodes;

        // Add all nodes with indegree 0 to the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform topological sorting
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (auto it : adjRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        // Sort the safe nodes in ascending order
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};