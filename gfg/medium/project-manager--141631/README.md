# Minimum Time to Finish Project

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

An IT company is working on a large project consisting of  **n**  modules.

- The given array time required (in months) to complete the ith module is stored in the array duration[].
- The array dependencies[][], where dependencies[i] = [u, v], indicates that module v can be started only after module u is completed. 

Multiple modules can be worked on simultaneously as long as all their dependencies have been completed.

Find the minimum time required to complete the entire project.

- If the project cannot be completed due to a cyclic dependency, return -1.
- A module is never dependent on itself.

 **Examples** 

```
Input: duration[] = [10, 20, 30, 10, 30, 20], dependencies[][] = [[5, 2], [5, 0], [4, 0], [4, 1], [2, 3], [3, 1]]
Output: 80
Explanation: 

The Graph of dependency forms this and the project will be completed when Module 1 is completed. The minimum taken time is 80 months, the maximum taken time is through the path 5 -> 2 -> 3 -> 1 which takes 20 + 30 + 10 + 20
```

```
Input: duration[] = [5, 5, 5], dependencies[][] = [[0, 1], [1, 2], [2, 0]]
Output: -1
Explanation: There is a cycle in the dependency graph hence the project cannot be completed.

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-30T18:06:35.637Z  

```cpp
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
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/project-manager--141631/1)