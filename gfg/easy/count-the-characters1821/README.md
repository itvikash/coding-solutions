# Count Group Occurrences

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a string  **s**  and an integer  **k**, count the number of distinct characters that appear in exactly  **k groups**  in the string.

A group is defined as one or more consecutive occurrences of the same character. For example, in the string "aaabbcca", the groups are "aaa", "bb", "cc" and "a".

 **Examples:** 

```
Input: s = "abc", k = 1
Output: 3
Explanation: The characters 'a', 'b' and 'c' each appear in exactly one group.
```

```
Input: s = "geeksforgeeks", k = 2
Output: 4
Explanation: The characters 'g', 'e', 'k' and 's' each appear in exactly two groups.
```

```
Input: s = "aaaaa", k = 2
Output: 0
Explanation: The character 'a' appears in only one group, so no character appears in exactly two groups.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-09T04:42:03.125Z  

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCount(string &s, int k) {
        unordered_map<char, int> group_counts;
        int n = s.length();

        for (int i = 0; i < n; ) {
            char curr = s[i];
            int j = i;
            while (j < n && s[j] == curr) {
                j++;
            }
            group_counts[curr]++;
            i = j;
        }

        int ans = 0;
        for (const auto& pair : group_counts) {
            if (pair.second == k) {
                ans++;
            }
        }

        return ans;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/count-the-characters1821/1)