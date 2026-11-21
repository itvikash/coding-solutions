# Smallest Subarray Sum Greater Than x

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer  **x** and an array of integers,  **arr[]**. Find the length of the smallest subarray whose sum is strictly greater than  **x**.

If no such subarray exists, return  **0**.

 **Examples:** 

```
Input: x = 51, arr[] = [1, 4, 45, 6, 0, 19]
Output: 3
Explanation: The smallest subarray with a sum greater than 51 is [4, 45, 6], whose sum is 55 and length is 3.
```

```
Input: x = 100, arr[] = [1, 10, 5, 2, 7]
Output: 0
Explanation: No subarray has a sum greater than 100. Hence, the answer is 0.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-21T14:28:53.744Z  

```cpp
class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int n = arr.size();
        int minLen = n + 1;
        long long currSum = 0;
        int start = 0;

        for (int end = 0; end < n; end++) {
            currSum += arr[end];

            while (currSum > x) {
                minLen = min(minLen, end - start + 1);
                currSum -= arr[start];
                start++;
            }
        }

        return (minLen == n + 1) ? 0 : minLen;
    }

    int smallestSubWithSum(vector<int>& arr, int x) {
        return smallestSubWithSum(x, arr);
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1)