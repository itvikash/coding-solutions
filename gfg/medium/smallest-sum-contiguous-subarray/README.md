# Minimum Sum Subarray

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array  **arr[]**, find the minimum sum of a subarray containing atleast one element in the given array.

 **Examples:** 

```
Input: arr[] = [3, -4, 2, -3, -1, 7, -5]
Output: -6
Explanation: The subarray [-4, 2, -3, -1] has the minimum sum, which is -6.
```

```
Input: arr[] = [4, -6, 3, -2, 5, -8, 2]
Output: -8
Explanation: The subarray [-8] has the minimum sum, which is -8.
```

```
Input: arr[] = [2, 6, 8, 1, 4]
Output: 1
Explanation: The subarray [1] has the minimum sum, which is 1.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-30T18:29:08.751Z  

```cpp
class Solution {
public:
int minSubarraySum(vector<int>& arr) {
int curr = arr[0];
int ans = arr[0];

for (int i = 1; i < arr.size(); i++) {
curr = min(arr[i], curr + arr[i]);
ans = min(ans, curr);
}

return ans;
}
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1)