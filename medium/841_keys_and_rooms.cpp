#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int room, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[room] = true; // Mark the current room as visited
        for (int key : rooms[room]) { // Visit all rooms accessible with keys in this room
            if (!visited[key]) {
                dfs(key, rooms, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false); 
        dfs(0, rooms, visited);

       
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
};