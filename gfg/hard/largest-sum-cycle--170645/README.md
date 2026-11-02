# Largest Sum Cycle

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an array   edge[]   of size   n , there are   n   cells numbered from   0   to   n - 1 . Each cell has at most one outgoing edge.

For every cell i:

- edge[i] is the cell reached from i in one step.
- edge[i] = -1 means that cell i has no outgoing edge.

A cycle is a sequence of cells where, by following the outgoing edges, we eventually return to the starting cell. The sum of a cycle is the sum of the indices of all cells in that cycle.

Return the maximum cycle sum. If there is no cycle, return -1.

  Examples:  

```
Input: edge[] = [1, 2, 0, -1]
Output: 3
Explanation: There is only one cycle in the graph i.e. 0 -> 1 -> 2 -> 0. Sum of the cell index in that cycle = 0 + 1 + 2 = 3.

```

```
Input: edge[] = [2, 0, -1, 2]
Output: -1
Explanation: There is no cycle in the graph. The edges are 1 -> 0 -> 2 <- 3. Hence, 2 has no outgoing edge, so no cycle exists.

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-02T15:26:08.099Z  

```cpp
class Solution {
public:
int largestSumCycle(vector<int>& edge) {
int n = edge.size();
vector<int> vis(n, 0);
long long ans = -1;

for (int i = 0; i < n; i++) {
if (vis[i]) continue;

int cur = i;

while (cur != -1 && vis[cur] == 0) {
vis[cur] = 1;
cur = edge[cur];
}

if (cur != -1 && vis[cur] == 1) {
long long sum = 0;
int temp = cur;

do {
sum += temp;
temp = edge[temp];
} while (temp != cur);

ans = max(ans, sum);
}

cur = i;

while (cur != -1 && vis[cur] == 1) {
vis[cur] = 2;
cur = edge[cur];
}
}

return (int)ans;
}
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/largest-sum-cycle--170645/1)