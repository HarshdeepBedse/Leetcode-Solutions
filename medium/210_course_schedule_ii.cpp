class Solution {
public:
    void topSortBfs(int n, vector<int>& topoOrder, unordered_map<int, list<int>>& adjList) {
        queue<int> q;
        map<int, int> indegree;
        
        // Initialize indegree for all nodes
        for (int i = 0; i < n; i++) {
            indegree[i] = 0;
        }
        
        // Calculate indegree for each node
        for (auto i : adjList) {
            for (auto nbr : i.second) {
                indegree[nbr]++;
            }
        }
        
        // Push all nodes with zero indegree into the queue
        for (int node = 0; node < n; node++) {
            if (indegree[node] == 0) {
                q.push(node);
            }
        }

        // Perform BFS
        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();
            topoOrder.push_back(frontNode);

            for (auto nbr : adjList[frontNode]) {
                indegree[nbr]--;

                // Check for zero indegree
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adjList;

        // Build the adjacency list
        for (vector<int> i : prerequisites) {
            int u = i[0];
            int v = i[1];
            adjList[v].push_back(u);
        }

        vector<int> topoSort;
        topSortBfs(numCourses, topoSort, adjList);

        // Check if a valid topological order is possible
        if (topoSort.size() == numCourses) {
            return topoSort;
        } else {
            return {};
        }
    }
};