# Minimize Max Min Diff with Subarray Removal

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an array  **arr[]**  of size  **n**. You need to remove a subarray of size  **k** , such that the difference between the maximum and minimum values of the remaining array is minimized. Find the minimum value obtained after performing the operation of the removal of the subarray.

 **Examples:** 

```
Input: arr = [1, 2, 3, 4, 5], k = 3 
Output: 1
Explanation: We remove first subarray of length 3, the remaining array is [4,5] and the difference of maximum and minimum element is 1 i.e 5 - 4 = 1
```

```
Input: arr = [2, 3, 1, 4, 6, 7], k = 3
Output: 2
Explanation: 
If we remove the subarray [2,3,1] then remaining array is [4,6,7] and the difference  = 7-4 = 3
If we remove the subarray [3,1,4] then remaining array is [2,6,7] and the difference  = 7-2 = 5
If we remove the subarray [1,4,6] then remaining array is [2,3,7] and the difference  = 7-2 = 5
If we remove the subarray [4,6,7] then remaining array is [2,3,1] and the difference  = 3-1 = 2
So the answer is min(3,5,5,2) = 2
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-26T18:07:47.216Z  

```cpp
#include <climits>
class Solution {
  public:
    int minDiff(int k, vector<int> &arr) {
        int n = arr.size();
        vector<int> prefMax(n+1,-1), prefMin(n+1, INT_MAX);
        vector<int> suffMax(n+1,-1), suffMin(n+1, INT_MAX);

        for(int i=0; i<n; i++){
            prefMax[i+1] = max(prefMax[i], arr[i]);
            prefMin[i+1] = min(prefMin[i], arr[i]);
        }

        for(int i=n-1; i>=0; i--){
            suffMax[i] = max(suffMax[i+1], arr[i]);
            suffMin[i] = min(suffMin[i+1], arr[i]);
        }

        int l = 0, r = k;
        int ans = INT_MAX;
        while(r<=n){
            int maxi = max(prefMax[l], suffMax[r]);
            int mini = min(prefMin[l], suffMin[r]);

            ans = min(ans, maxi - mini);
            r++, l++;
        }
        return ans;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/minimize-the-difference/1)