# Subsets with MEX in Range

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an array **arr[]** of integers and a range  **[l, r]**, count the number of subsets whose Minimum Excluded (MEX) value lies within the given range, inclusive.

- Minimum Excluded (or MEX) of a subset is the smallest non-negative integer that is not present in the subset.
- An empty subset has Minimum Excluded as zero.

Since the answer can be very large, return the answer modulo  **109 + 7**.

 **Examples:** 

```
Input: arr[] = [2, 0, 1, 0], l = 1, r = 2
Output: 9
Explanation: The subsets whose MEX lies in the range [1, 2] are counted as follows:
MEX = 1: The subsets must contain at least one 0 and must not contain 1. These subsets are [0] (2 ways), [2, 0] (2 ways), [0, 0] (1 way), and [2, 0, 0] (1 way). Total = 6.
MEX = 2: The subsets must contain both 0 and 1 but must not contain 2. These subsets are [0, 1] (2 ways) and [0, 1, 0] (1 way). Total = 3.
The subsets [2, 0, 1] and [2, 0, 1, 0] have MEX = 3, which is outside the given range. Therefore, the total number of valid subsets is 6 + 3 = 9.
```

```
Input: arr[] = [2, 0, 1], l = 1, r = 2
Output: 3
Explanation: The subsets whose MEX lies in the range [1, 2] are [0] (MEX = 1), [2, 0] (MEX = 1), and [0, 1] (MEX = 2). Hence, the answer is 3.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-30T18:02:03.109Z  

```cpp
class Solution {
  public:
    int cntSubsets(vector<int> &arr, int l, int r) {
        int n = arr.size();
        long long MOD = 1e9 + 7;

        vector<long long> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> freq(r + 1, 0);
        for (int x : arr) {
            if (x <= r) {
                freq[x]++;
            }
        }

        long long ans = 0;
        long long running_ways = 1;
        int pref = 0;

        for (int M = 0; M <= r; M++) {
            pref += freq[M];
            int C = n - pref;

            if (M >= l) {
                long long ways = (running_ways * pow2[C]) % MOD;
                ans = (ans + ways) % MOD;
            }

            long long ways_to_pick_M = (pow2[freq[M]] - 1 + MOD) % MOD;
            running_ways = (running_ways * ways_to_pick_M) % MOD;

            if (running_ways == 0) { break; }
        }

        return ans;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/crazy-subsets--131708/1)