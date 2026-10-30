# Perimeter of Shapes in Binary Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a binary matrix  **mat[][]**  of size  **n × m**, where each cell contains either  **0**  or  **1**, find the total perimeter of all figures formed by cells containing  **1s**. Two cells are considered adjacent if they share a common side.

A single cell containing 1 has a perimeter of 4, whereas two adjacent cells containing 1 (i.e., 11) together have a perimeter of 6.

 

 **Examples :** 

```
Input: mat[][] = [[0,1,0,0,0], [1,1,1,0,0], [1,0,0,0,0]]
Output: 12
Explanation: The five cells form a single figure. Hence, the perimeter of the figure is 12.     

```

```
Input: mat[][] = [[1,0], [1,1]]
Output: 8
Explanation: The two adjacent cells share one common side. Hence, the perimeter of the figure is 6.  

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-30T18:09:22.884Z  

```cpp
class Solution {
public:
int findPerimeter(vector<vector<int>>& mat) {
int n = mat.size();
int m = mat[0].size();
int perimeter = 0;
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
if (mat[i][j] == 1) {
if (i == 0 || mat[i - 1][j] == 0)
perimeter++;
if (i == n - 1 || mat[i + 1][j] == 0)
perimeter++;
if (j == 0 || mat[i][j - 1] == 0)
perimeter++;
if (j == m - 1 || mat[i][j + 1] == 0)
perimeter++;
}
}
}
return perimeter;
}
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/find-perimeter-of-shapes/1)