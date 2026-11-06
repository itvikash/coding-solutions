# Balanced Binary Tree Counter

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a height  **h**, find the maximum number of distinct balanced binary trees of height exactly h.

A binary tree is balanced if, for every node, the heights of its left and right subtrees differ by at most 1. A tree with a single node has height 1. An empty tree has height 0.

 **Note:**  Since the answer can be very large, return it modulo 109 + 7.

 **Examples:** 

```
Input: h = 1
Output: 1
Explanation: Only one tree of height 1 exists i.e. a single node.
```

```
Input: h = 2
Output: 3 
Explanation: 3 distinct balanced trees of height 2 exist.

```

```
Input: h = 3
Output: 15
Explanation: 15 distinct balanced trees of height 3 exist.

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-06T16:56:30.008Z  

```cpp
class Solution {
public:
    long long int countBT(int h) {
        if (h == 0 || h == 1) return 1;

        long long int MOD = 1e9 + 7;
        long long int dp0 = 1; // dp[i-2]
        long long int dp1 = 1; // dp[i-1]
        long long int dp2;    // dp[i]

        for (int i = 2; i <= h; i++) {
            dp2 = (dp1 * (dp1 + 2 * dp0)) % MOD;
            dp0 = dp1;
            dp1 = dp2;
        }

        return dp1;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/bbt-counter4914/1)