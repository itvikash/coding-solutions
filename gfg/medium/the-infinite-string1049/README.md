# Character at Position in Infinite String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string  **s**  and an integer  **pos**, an infinite string is constructed by repeatedly applying the following operation. In the i-th step, append i consecutive $ characters, followed by the reverse of the current string, to the current string.

Formally, if the current string is s, update it as:

- s = s + ('$' repeated i times) + reverse(s)

The initial string is the given s, and the process continues indefinitely.

Find and return the character at the pos(1-based indexing) in the resulting infinite string.

 **Examples:** 

```
Input: s = "12345", pos = 3
Output: 3
Explanation: In "12345...", the character at pos 3 is 3.

```

```
Input: s = "12345", pos = 10
Output: 2
Explanation: In "12345$54321...", the character at pos 10 is 2.

```

```
Input: s = "abc", pos = 7
Output: a
Explanation: In "abc$cba...", the character at pos 7 is a.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-23T03:02:50.613Z  

```cpp
class Solution {
  public:
    char posInfinite(string &s, int pos) {
        long long n = s.size();
        vector<long long> lengths = {n};
        int step = 1;

        while (lengths.back() < pos) {
            long long next_len = 2 * lengths.back() + step;
            lengths.push_back(next_len);
            step++;
        }

        long long p = pos;
        for (int i = (int)lengths.size() - 1; i >= 1; i--) {
            long long prev_len = lengths[i - 1];
            int mid_dollars = i;

            if (p <= prev_len) {
                continue;
            } else if (p <= prev_len + mid_dollars) {
                return '$';
            } else {
                long long offset = p - (prev_len + mid_dollars);
                p = prev_len - offset + 1;
            }
        }

        return s[p - 1];
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/the-infinite-string1049/1)