# Range Vowel Count Queries

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a string  **s**  and a 2D array  **queries[][]**, where each query consists of two integers  **l**  and  **r**, find the number of vowels in the substring  **s[l....r]**  for each query. The substring includes both indices l and r.

Return an array containing the answers to all queries in the order they are given.

 **Examples:** 

```
Input: s = "geeksforgeeks", queries[][] = [[1, 3], [2, 4], [1, 9]]
Output: [2, 1, 4]
Explanation:
Query 1: "eek" has 2 vowels (e, e).
Query 2: "eks" has 1 vowel (e).
Query 3: "eeksforge" has 4 vowels (e, e, o, e).
```

```
Input: s = "helloworld", queries[][] = [[0, 4], [5, 9], [0, 9]]
Output: [2, 1, 3]
Explanation:
Query 1: "hello" has 2 vowels (e, o).
Query 2: "world" has 1 vowel (o).
Query 3: "helloworld" has 3 vowels (e, o, o).
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-26T04:08:34.239Z  

```cpp
class Solution {
  public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<int> countVowels(string& s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (isVowel(s[i]) ? 1 : 0);
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            ans.push_back(pref[r + 1] - pref[l]);
        }

        return ans;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/range-vowel-count-queries-static/1)