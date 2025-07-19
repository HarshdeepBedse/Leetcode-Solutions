
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build the adjacency list
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            graph[u].emplace_back(v, w);
        }

        // Step 2: Use a priority queue for Dijkstra's algorithm
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k); // (current_time, node)

        while (!pq.empty()) {
            auto [current_time, node] = pq.top();
            pq.pop();

            // If the current time is already greater than recorded distance, skip
            if (current_time > dist[node]) continue;

            // Step 3: Relax the edges
            for (const auto& [neighbor, weight] : graph[node]) {
                if (current_time + weight < dist[neighbor]) {
                    dist[neighbor] = current_time + weight;
                    pq.emplace(dist[neighbor], neighbor);
                }
            }
        }

        // Step 4: Find the maximum time required
        int max_time = *max_element(dist.begin() + 1, dist.end());
        return max_time == INT_MAX ? -1 : max_time;
    }
};