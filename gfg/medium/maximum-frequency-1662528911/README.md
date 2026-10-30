# Maximum Frequency with K Increments

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array  **arr[]**. In one operation, you can choose an index and increment its value by 1.

Find the maximum possible frequency of any element after performing at most k operations.

 **Examples:** 

```
Input: arr[] = [2, 2, 4], k = 4
Output: 3
Explanation: Apply two increment operations on index 0 and two operations on index 1 to make arr[]= [4, 4, 4]. Frequency of 4 is 3.

```

```
Input: arr[] = [7, 7, 7, 7], k = 5
Output: 4
Explanation: The frequency of 7 is already 4, so no operations are needed.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-30T18:15:47.762Z  

```cpp
class Solution {
public:
int maxFrequency(vector<int>& arr, int k) {
sort(arr.begin(), arr.end());
long long sum = 0;
int left = 0;
int ans = 1;
for (int right = 0; right < arr.size(); right++) {
sum += arr[right];
while ((long long)arr[right] * (right - left + 1) - sum >
k) {
sum -= arr[left];
left++;
}
ans = max(ans, right - left + 1);
}
return ans;
}
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/maximum-frequency-1662528911/1)