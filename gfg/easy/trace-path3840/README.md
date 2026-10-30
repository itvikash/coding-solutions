# Trace Path

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a rectangular grid with  **n** rows and  **m** columns, and a string  **s**  representing a sequence of movement commands. Geek can start from any cell of the grid and follows all the commands in s in the same order.

The string s consists only of the characters L, R, D, and U, where:

- L: Move one cell left, from (i, j) to (i, j - 1).
- R: Move one cell right, from (i, j) to (i, j + 1).
- U: Move one cell up, from (i, j) to (i - 1, j).
- D: Move one cell down, from (i, j) to (i + 1, j).

Determine whether there exists at least one starting cell such that Geek remains within the grid while following all the commands in s.

 **Examples:** 

```
Input: n = 1, m = 1, s = "R"
Output: false
Explanation: There is only one cell(1, 1). So Geek can only start from (1, 1). On taking right(R) Geek moves to (1, 2), which is out of grid. Therefore, there is no cell from where Geek can start and remain inside the grid after tracing the route. 
```

```
Input: n = 2, m = 3, s = "LLRD"
Output: true
Explanation: One possible cell is (1, 3). (1, 3) -> (1, 2) -> (1, 1) -> (1, 2) -> (2, 2). Thus, there is a cell from where if Geek starts, it remains inside the grid throughout tracing the route.

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-30T18:37:13.103Z  

```cpp
class Solution {
public:
bool isPossible(int n, int m, string &s) {
int x = 0, y = 0;
int minX = 0, maxX = 0;
int minY = 0, maxY = 0;

for (char c : s) {
if (c == 'L') y--;
else if (c == 'R') y++;
else if (c == 'D') x++;
else if (c == 'U') x--;

minX = min(minX, x);
maxX = max(maxX, x);
minY = min(minY, y);
maxY = max(maxY, y);
}

return (maxX - minX < n &&
maxY - minY < m);
}
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/trace-path3840/1)