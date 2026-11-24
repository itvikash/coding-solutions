# Two Pairs with Same Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array  **arr[]**  of positive integers, find four indices  **a**,  **b**,  **c**, and  **d**  such that arr[a] + arr[b] = arr[c] + arr[d], where a, b, c, d are all distinct indices.

- If multiple such quadruplets exist, return the one that is lexicographically smallest when the indices are considered in the order a, b, c, d.
- If no such quadruplet exists, return {-1, -1, -1, -1}. 
- Ensure a < b and c < d, and the pair (a, b) is lexicographically smaller than the pair (c, d).

 **Examples:** 

```
Input: arr[] = [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5]
Explanation: arr[0] + arr[2] = 3 + 7 = 10, arr[3] + arr[5] = 1 + 9 = 10. 
This is the lexicographically smallest such quadruplet of indices.
```

```
Input: arr[] = [1, 2, 3, 3]
Output: [-1, -1, -1, -1]
Explanation: No two distinct pairs of indices produce the same sum.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-24T13:43:36.299Z  

```cpp
class Solution {
  public:
    vector<int> findPairs(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, pair<int, int>> sumMap;
        vector<int> ans = {n, n, n, n};
        bool found = false;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = arr[i] + arr[j];

                if (sumMap.find(sum) == sumMap.end()) {
                    sumMap[sum] = {i, j};
                } else {
                    pair<int, int> p = sumMap[sum];
                    int a = p.first, b = p.second;

                    if (a != i && a != j && b != i && b != j) {
                        vector<int> curr;
                        if (make_pair(a, b) < make_pair(i, j)) {
                            curr = {a, b, i, j};
                        } else {
                            curr = {i, j, a, b};
                        }

                        if (!found || curr < ans) {
                            ans = curr;
                            found = true;
                        }
                    }
                }
            }
        }

        return found ? ans : vector<int>{-1, -1, -1, -1};
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/satisfy-the-equation5847/1)