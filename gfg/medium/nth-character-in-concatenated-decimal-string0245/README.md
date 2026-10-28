# Nth in Concatenated Decimal String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Consider a string  **s**  formed by concatenating the decimal representations of all positive integers in order:

s = "12345678910111213141516171819202122232425262728293031..."

Given an integer **n**, find the nth character (1-based indexing) in the string s.

 **Examples:** 

```
Input: n = 10
Output: '1'
Explanation: The 10th in "1234567891.." character is '1'.
```

```
Input: n = 11
Output: '0'
Explanation: The 11th character in "12345678910.."  is '0'.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-28T15:33:36.525Z  

```cpp
class Solution {
public:
 char nthCharacter(int n) {
 long long pos = n;
 long long len = 9;
 long long start = 1;
 long long digits = 1;
 while (pos > len * digits) {
pos -= len * digits;
 len *= 10;
 start *= 10;
 digits++;
 }
  long long number = start + (pos - 1) / digits;
 int index = (pos - 1) % digits;
 string s = to_string(number);
 return s[index];
 }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/nth-character-in-concatenated-decimal-string0245/1)