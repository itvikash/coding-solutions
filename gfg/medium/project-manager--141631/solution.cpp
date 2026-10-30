class Solution {
public:
int minTime(vector<int>& duration, vector<vector<int>>& dependencies) {
int n = duration.size();
vector<vector<int>> adj(n);
vector<int> indegree(n, 0);
for (auto &d : dependencies) {
int u = d[0];
int v = d[1];
adj[u].push_back(v);
indegree[v]++;
}
queue<int> q;
vector<long long> dp(n, 0);
for (int i = 0; i < n; i++) {
if (indegree[i] == 0) {
q.push(i);
dp[i] = duration[i];
}
}
int count = 0;
long long ans = 0;
while (!q.empty()) {
int u = q.front();
q.pop();
count++;
ans = max(ans, dp[u]);
for (int v : adj[u]) {
dp[v] = max(dp[v], dp[u] + duration[v]);
indegree[v]--;
if (indegree[v] == 0) {
q.push(v);
}
}
}
if (count != n)
return -1;
return (int)ans;
}
};