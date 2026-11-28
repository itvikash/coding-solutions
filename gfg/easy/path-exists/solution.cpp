#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    bool checkPath(vector<vector<int>>& adj, int src, int dest) {
        int V = adj.size();
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == dest) return true;

            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};