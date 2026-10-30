# Count Indices That Escape Array

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array  **arr[]**, where arr[i] represents the exact number of steps to move from index i.  An index is considered good if repeatedly following the jumps eventually takes you outside the array. Otherwise, if the jumps result in an infinite loop, the index is considered bad.

- A positive value indicates a move to the right
- A negative value indicates a move to the left.
- A 0 value means no move and considered bad.

Return the number of good indices.

 **Examples:** 

```
Input: [2, 3, -1, 2, -2, 4, 1]
Output: 3
Explanation: Indices 3, 5, and 6 are good because their jump sequences eventually leave the array. Indices 1, 2, and 4 form a cycle, while index 0 eventually enters this cycle through index 2. Hence, the total number of good indices is 3.
 
```

```
Input: [1, 0, -3, 0, -5, 0]
Output: 2
Explanation: Indices 2 and 4 are good because their jumps take them outside the array. Indices 1, 3, and 5 are bad because their jumps are zero. Index 0 is also bad because it jumps to index 1, which is a dead end. Hence, the total number of good indices is 2.
  
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-30T18:26:33.941Z  

```cpp
class Solution {
public:
int goodIndices(vector<int>& arr) {
int n = arr.size();
vector<int> dp(n, 0);

function<bool(int)> dfs = [&](int i) {
if (i < 0 || i >= n)
return true;

if (dp[i] != 0)
return dp[i] == 1;

if (arr[i] == 0) {
dp[i] = -1;
return false;
}

dp[i] = -1;
int next = i + arr[i];

if (dfs(next)) {
dp[i] = 1;
return true;
}

return false;
};

int ans = 0;

for (int i = 0; i < n; i++) {
if (dfs(i))
ans++;
}

return ans;
}
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/good-stones--170647/1)