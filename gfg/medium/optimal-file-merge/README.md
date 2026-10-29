# Optimal File Merge

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array  **files[]**, where  **files[i]**  represents the size of the i-th file, merge all the files into a single file with the minimum total computation cost.

The cost of merging two files of sizes  **x** and  **y** is  **x + y**. After merging, a new file of size **x + y**  is created, which can be merged further with other files.

Return the minimum total cost required to merge all the files.

 **Note:**  It is guaranteed that the minimum total computation cost fits within a 32-bit signed integer.

 **Examples:** 

```
Input: files[] = [3, 2, 4]
Output: 14
Explanation: There are different ways to combine these files. Optimal method is given below:

```

```
Input: files[] = [2, 3, 6, 5, 7, 4]
Output: 68
Explanation: There are different ways to combine these files. Optimal method is given below:

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-29T13:24:22.949Z  

```cpp
class Solution {
  public:
    int minComputation(vector<int> &files) {
        multiset<int> s;
        int n = files.size();
        for(int i=0; i<n; i++){
            s.insert(files[i]);
        }
        int ans = 0;
        while(s.size() != 1){
            auto it = next(s.begin(),1);
            int val = *s.begin() + *it;
            ans += val;

            s.erase(s.begin());
            s.erase(s.begin());
            s.insert(val);
        }
        return ans;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/optimal-file-merge/1)