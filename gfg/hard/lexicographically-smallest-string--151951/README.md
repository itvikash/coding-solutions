# Lexicographically Smallest Rotation

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string  **s**, find the lexicographically smallest string after rotating the string left any number of times including 0.

 **Example:** 

```
Input: s = "abcd"
Output: "abcd"
Explanation: String after each rotation are "abcd", "bcda", "cdab", "dabc" and so on. Lexicographically smallest among them is "abcd".

```

```
Input: s = "baca"
Output: "abac"
Explanation: Strings after each rotation are "baca", "acab", "caba", "abac" and so on. Lexicographically smallest among them is "abac".
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-30T18:07:59.061Z  

```cpp
class Solution {
public:
string lexiString(string s) {
int n = s.size();
string t = s + s;
int i = 0, j = 1, k = 0;
while (i < n && j < n && k < n) {
if (t[i + k] == t[j + k]) {
k++;
}
else if (t[i + k] > t[j + k]) {
i = i + k + 1;
if (i == j)
i++;
k = 0;
}
else {
j = j + k + 1;
if (i == j)
j++;
k = 0;
}
}
int start = min(i, j);
return t.substr(start, n);
}
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/lexicographically-smallest-string--151951/1)