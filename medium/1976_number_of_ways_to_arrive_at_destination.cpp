const int MOD = 1e9 + 7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            
            if (d > dist[node]) continue;
            
            for (auto& [neighbor, time] : adj[node]) {
                long long newDist = d + time;
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    ways[neighbor] = ways[node];
                    pq.push({newDist, neighbor});
                } else if (newDist == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }
        
        return ways[n - 1];
    }
};