class Solution {
  public:
    int countEdges(vector<vector<int>>& adj) {
        int totalDegree = 0;
        for (int i = 0; i < adj.size(); i++) {
            totalDegree += adj[i].size();
        }
        return totalDegree / 2;
    }
};