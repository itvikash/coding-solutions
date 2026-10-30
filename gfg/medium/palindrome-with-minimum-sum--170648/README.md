# Palindrome with Replacement

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string  **s**  consisting of lowercase English letters and the character '?', 

- Replace every '?' with a lowercase English letter such that the resulting string is a palindrome.
- If it is possible to form a palindrome, return the minimum possible sum of the absolute ASCII differences between every pair of adjacent characters in the resulting string.
- If it is not possible to form a palindrome, return -1.

 **Examples:** 

```
Input: s = a???c??c????
Output: 4
Explanation: One optimal palindrome is "abbbccccbbba". The sum of the absolute ASCII differences between adjacent characters is 1 + 0 + 0 + 1 + 0 + 0 + 0 + 1 + 0 + 0 + 1 = 4, which is the minimum possible. 
```

```
Input: s = a???c??c???c
Output: -1
Explanation: It is not possible to replace the '?' characters to make the string a palindrome because the first and last characters are different and cannot be changed.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-30T18:29:39.961Z  

```cpp
class Solution {
public:
int minimumSum(string s) {
int n = s.size();

for (int i = 0; i < n / 2; i++) {
int j = n - 1 - i;

if (s[i] != '?' && s[j] != '?' && s[i] != s[j])
return -1;

if (s[i] == '?' && s[j] != '?')
s[i] = s[j];
else if (s[j] == '?' && s[i] != '?')
s[j] = s[i];
}

int i = 0;

while (i < n) {
if (s[i] != '?') {
i++;
continue;
}

int j = i;
while (j < n && s[j] == '?')
j++;

char left = (i > 0) ? s[i - 1] : '?';
char right = (j < n) ? s[j] : '?';

char c = 'a';

if (left != '?' && right != '?')
c = (left < right) ? left : right;
else if (left != '?')
c = left;
else if (right != '?')
c = right;

for (int k = i; k < j; k++)
s[k] = c;

i = j;
}

int ans = 0;

for (int k = 1; k < n; k++)
ans += abs(s[k] - s[k - 1]);

return ans;
}
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/palindrome-with-minimum-sum--170648/1)