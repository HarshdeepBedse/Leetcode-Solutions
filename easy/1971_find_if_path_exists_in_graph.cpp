#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <list>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, list<int>> adjlist;

        // Build the adjacency list for the graph
        for (const auto& edge : edges) {
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }

        queue<int> q; // Queue to process nodes in BFS order
        map<int, bool> visited; // Map to keep track of visited nodes

        // Start BFS with the given source node
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            
            if (current == destination) {
                return true;
            }

           
            for (int neighbour : adjlist[current]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }

     
        return false;
    }
};