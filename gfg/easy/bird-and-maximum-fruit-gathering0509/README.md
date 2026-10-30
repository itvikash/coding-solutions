# Maximum Packages within Time

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

A delivery agent has to deliver packages at locations arranged in a line. The number of packages at the **ith**  location is given by  **arr[i]**.

- The agent can start at any location and can only visit consecutive locations.
- Visiting each location takes 1 unit of time.

Given  **arr[]**  and  **totalTime**, find the maximum number of packages the agent can deliver within  **totalTime**.

 **Examples:** 

```
Input: arr[] = [2, 1, 3, 5, 0, 1, 4], totalTime = 3
Output: 9
Explanation: The agent can visit three consecutive locations. Starting from the second location, it delivers arr[1] + arr[2] + arr[3] = 1 + 3 + 5 = 9 packages.
```

```
Input: arr[] = [1, 6, 2, 5, 3, 4], totalTime = 2
Output: 8
Explanation: The agent can visit two consecutive locations. Starting from the second location, it delivers arr[1] + arr[2] = 6 + 2 = 8 packages. Starting from the fourth location gives arr[3] + arr[4] = 5 + 3 = 8 packages. Hence, the maximum is 8 packages.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-30T18:54:41.549Z  

```cpp
class Solution {
  public:
    int maxPackages(vector<int>& arr, int totalTime) {
        // code here
        int ans = LLONG_MIN;
        int n = arr.size();
        int sum = 0;
        for(int i=0; i<min(totalTime, n); i++){
            sum += arr[i];
        }
        int r = min(totalTime, n);
        int l = 0;

        while(r < n){
            ans = max(ans, sum);
            sum -= arr[l];
            sum += arr[r];
            r++; l++;
        }
        ans = max(ans, sum);
        return ans;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/bird-and-maximum-fruit-gathering0509/1)