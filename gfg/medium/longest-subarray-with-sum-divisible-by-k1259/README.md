# Longest Subarray Sum Divisible by K

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array  **arr[]**  and a positive integer  **k**, find the length of the longest subarray whose sum is divisible by k.

 **Note:** If there is no subarray with sum divisible by k, then return 0.

 **Examples:** 

```
Input: arr[] = [2, 7, 6, 1, 4, 5], k = 3
Output: 4
Explanation: The subarray [7, 6, 1, 4] has sum = 18, which is divisible by 3.
```

```
Input: arr[] = [-2, 2, -5, 12, -11, -1, 7], k = 3
Output: 5
Explanation: The subarray [2, -5, 12, -11, -1] has sum = -3, which is divisible by 3.

```

```
Input: arr[] = [1, 2, -2], k = 2
Output: 2
Explanation: The subarray is [2, -2] has sum = 0, which is divisible by 2.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-22T04:23:27.728Z  

```cpp
class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        unordered_map<int, int> remMap;
        long long prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];
            int rem = ((prefixSum % k) + k) % k;

            if (rem == 0) {
                maxLen = i + 1;
            } else if (remMap.find(rem) != remMap.end()) {
                maxLen = max(maxLen, i - remMap[rem]);
            } else {
                remMap[rem] = i;
            }
        }

        return maxLen;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1)