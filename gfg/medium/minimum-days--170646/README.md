# Minimum Days

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string  **s**  of length n containing only lowercase English letters, and a permutation array  **p[]**  of length n containing integers from 0 to n - 1.

On the (i + 1)th day, the character at index p[i] in the string is replaced with '?'. For example:

- On day 1, replace s[p[0]] with '?'.
- On day 2, replace s[p[1]] with '?'.
- On day 3, replace s[p[2]] with '?'.
- And so on.

Find the minimum number of days required so that no two adjacent characters in s are equal, unless at least one of them is '?'.

Formally, for every index i (0 <= i < n - 1), the string must satisfy: If s[i] != '?' and s[i+1] != '?', then s[i] != s[i+1].

 **Examples:** 

```
Input: s = "aabb", p = [2, 1, 3, 0]
Output: 2
Explanation:
On Day 1, we replace s[p[0]] (index 2) with '?'. String becomes "aa?b". Index 0 and 1 still have equal adjacent characters 'a'.
On Day 2, we replace s[p[1]] (index 1) with '?'. String becomes "a??b". Now no two adjacent non-'?' characters are equal.
```

```
Input: s = "abca", p = [3, 0, 2, 1]
Output: 0
Explanation:
The initial string "abca" already satisfies the condition without replacing any characters.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-05T16:22:25.460Z  

```cpp
class Solution {
public:
 int getMinimumDays(string &s, vector<int> &p) {
  int n = s.size();
int bad = 0;
    for (int i = 0; i < n - 1; i++) {
if (s[i] == s[i + 1])
bad++;
}
  if (bad == 0)
return 0;
 vector<int> removed(n, 0);
  for (int day = 0; day < n; day++) {
int x = p[day];
  if (x > 0 && !removed[x - 1] && s[x - 1] == s[x])
bad--;
  if (x < n - 1 && !removed[x + 1] && s[x] == s[x + 1])
bad--;
 removed[x] = 1;
  if (bad == 0)
return day + 1;
 } return n;
 }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/minimum-days--170646/1)