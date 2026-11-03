# Count Tree Paths With Limited Max Edge Weight

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a weighted tree with  **n**  nodes, numbered from 1 to n and n - 1 edges, where each edge is represented as [u, v, w] indicating an edge between nodes u and v with weight w.

You are also given an array  **queries[]**, where each queries[i] represents a maximum allowed edge weight.

For each query x, find the number of distinct paths in the tree such that the maximum edge weight along the path is less than or equal to x.

Return an array containing the number of valid paths for each query.

 **Note:** 

- A path from node u to node v and the path from node v to node u are considered the same path.
- A path must contain at least one edge. A path from a node to itself is not considered.

 **Examples:** 

```
Input: n = 3, edges[][] = [[1, 2, 1], [2, 3, 4]], queries[] = [3]
Output: [1]
Explanation:
For x = 3, only the edge [1, 2, 1] has weight less than or equal to 3.
Therefore, the only valid path is: 1 -> 2
The path 1 -> 3 contains an edge of weight 4, so it is not valid.
Hence, the answer is 1.
```

```
Input: n = 7, edges[][] = [[1, 2, 3], [2, 3, 1], [2, 4, 9], [3, 6, 7], [3, 5, 8], [5, 7, 4]], queries[] = [1, 3, 5]
Output: [1, 3, 4]
Explanation: For x = 1, only the edge [2, 3, 1] satisfies the condition. 
Therefore, the only valid path is 2 -> 3, giving an answer of 1.
For x = 3, the edges [2, 3, 1] and [1, 2, 3] can be used. 
They form three valid paths: 1 -> 2, 2 -> 3, and 1 -> 3. 
For x = 5, the edges with weights 1, 3, and 4 can be used. 
They form four valid paths: 1 -> 2, 2 -> 3, 1 -> 3, and 5 -> 7.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-03T15:37:27.140Z  

```cpp
class Solution { 
public: 
 vector<int> parent, sz; 
 int find(int x) { 
 if (parent[x] != x) 
 parent[x] = find(parent[x]); 
 return parent[x]; 
 } 
 long long unite(int a, int b) { 
 a = find(a); 
 b = find(b); 
 if (a == b) return 0; 
 if (sz[a] < sz[b]) 
 swap(a, b); 
 long long ans = 1LL * sz[a] * sz[b]; 
 parent[b] = a; 
 sz[a] += sz[b]; 
 return ans; 
 } 
 vector<int> maximumWeight(int n, vector<vector<int>>& edges,  vector<int>& queries) { 
 sort(edges.begin(), edges.end(),
 [](const vector<int>& a, const vector<int>& b) {  return a[2] < b[2]; 
 }); 
 int q = queries.size(); 
 vector<pair<int, int>> qu; 
 for (int i = 0; i < q; i++) 
 qu.push_back({queries[i], i}); 
 sort(qu.begin(), qu.end()); 
 parent.resize(n + 1); 
 sz.assign(n + 1, 1); 
 for (int i = 1; i <= n; i++) 
 parent[i] = i; 
 vector<int> ans(q); 
 long long cnt = 0; 
 int j = 0; 
 for (auto &p : qu) { 
 int x = p.first; 
 int idx = p.second; 
 while (j < edges.size() && edges[j][2] <= x) {  cnt += unite(edges[j][0], edges[j][1]);  j++; 
 }
 ans[idx] = cnt;  } 
 return ans; 
 } 
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/possible-paths--141628/1)