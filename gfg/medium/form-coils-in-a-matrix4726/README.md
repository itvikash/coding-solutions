# Coils in Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a positive integer n, consider a 4n  *4n matrix filled with integers from 1 to (4n)*  (4n) in row-major order (left to right, top to bottom). Form two coils from the matrix:

- The first coil starts from the top-left cell (0, 0) and spirals inward.
- The second coil starts from the bottom-right cell (4n - 1, 4n - 1) and spirals inward in the opposite direction.

Return these two coils in the same order.

 **Examples:** 

```
Input: n = 1
Output: [[1, 5, 9, 13, 14, 15, 11, 7], [16, 12, 8, 4, 3, 2, 6, 10]] 
Explanation: The matrix is 
 
So, the two coils are as given in the Output.
```

```
Input: n = 2
Output:
[[1, 9, 17, 25, 33, 41, 49, 57, 58, 59, 60, 61, 62, 63, 55, 47, 39, 31, 23, 15, 14, 13, 12, 11, 19, 27, 35, 43, 44, 45, 37, 29], 
 [64, 56, 48, 40, 32, 24, 16, 8, 7, 6, 5, 4, 3, 2, 10, 18, 26, 34, 42, 50, 51, 52, 53, 54, 46, 38, 30, 22, 21, 20, 28, 36]]  
Explanation:
 

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-30T18:08:42.010Z  

```cpp
class Solution {
public:
vector<vector<int>> formCoils(int n) {
int m = 4 * n;
int total = m * m;
vector<int> a, b;
int top = 0, bottom = m - 1;
int left = 0, right = m - 1;
while (top <= bottom && left <= right) {

for (int i = top; i <= bottom; i++)
a.push_back(i * m + left + 1);
for (int j = left + 1; j < right; j++)
a.push_back(bottom * m + j + 1);

for (int i = bottom - 1; i > top; i--)
a.push_back(i * m + right - 1 + 1);

for (int j = right - 2; j > left + 1; j--)
a.push_back((top + 1) * m + j + 1);
top += 2;
bottom -= 2;
left += 2;
right -= 2;
}
for (int x : a)
b.push_back(total + 1 - x);
return {a, b};
}
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/form-coils-in-a-matrix4726/1)