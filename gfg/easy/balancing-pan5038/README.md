# Balancing with Distinct Powers

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a simple weighing scale with two pans, a target weight  **b**, and a set of weights where each weight is a distinct power of  **a**, find if the scale can be balanced such that:

b + (some powers of a) = (some other powers of a)

 **Note:**  Exactly one weight is available for each power of a, so each power can be used at most once.

 **Examples:** 

```
Input: a = 4, b = 11
Output: true
Explanation: 11 + 4 + 1 = 16. So, target = 11 can be balanced using powers of 4.
```

```
Input: a = 3, b = 5
Output: true
Explanation: 5 + 3 + 1 = 9. So, target = 5 can be balanced using powers of 3.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-30T18:16:58.486Z  

```cpp
class Solution {
public:
bool balancePan(int a, int b) {
long long B = b;
long long A = a;
while(B > 0){
long long r = B % A;
B /= A;
if(r == 0 || r == 1) continue;
if(r == A-1){
B += 1;
continue;
}
return false;
}
return true;
}
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/balancing-pan5038/1)