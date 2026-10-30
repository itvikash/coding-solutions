# Minimum Operations to Reach n

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a number  **n**. Find the minimum number of operations required to reach n starting from 0.

You have two operations available:

- Double the number
- Add one to the number

 **Examples:** 

```
Input: n = 8
Output: 4
Explanation: 0 + 1 = 1 --> 1 + 1 = 2 --> 2  *2 = 4 --> 4*  2 = 8.

```

```
Input: n = 7
Output: 5
Explanation: 0 + 1 = 1 --> 1 + 1 = 2 --> 1 + 2 = 3 --> 3 * 2 = 6 --> 6 + 1 = 7.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-30T18:16:31.178Z  

```cpp
class Solution {
public:
int minOperation(int n) {
int ans = 0;

while (n > 0) {
if (n % 2 == 0)
n = n / 2;
else
n = n - 1;

ans++;
}

return ans;
}
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/find-optimum-operation4504/1)