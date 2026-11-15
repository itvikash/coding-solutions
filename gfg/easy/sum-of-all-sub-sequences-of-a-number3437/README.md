# Sum of All Digit Subsequences

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a string **s**  which consists of digits, find sum of all digits across all non-empty subsequences of s.

 **Note:**  Since the answer can be very large, return it modulo 10^9 + 7.

 **Examples:** 

```
Input: s = "123" 
Output: 24
Explanation: The non-empty subsequences are: [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]. The sum of all digits in these subsequences is: 1 + 2 + 3 + (1 + 2) + (1 + 3) + (2 + 3) + (1 + 2 + 3) = 24.

```

```
Input: s = "405"
Output: 36
Explanation: The non-empty subsequences are: [4], [0], [5], [4, 0], [4, 5], [0, 5], [4, 0, 5]. The sum of all digits in these subsequences is 36.

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-15T04:07:18.559Z  

```cpp
#include <string>

using namespace std;

class Solution {
private:
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }

public:
    long long subsequenceSum(string s) {
        long long MOD = 1000000007;
        long long sum_digits = 0;
        int n = s.length();

        for (char c : s) {
            sum_digits = (sum_digits + (c - '0')) % MOD;
        }

        long long total_sum = (sum_digits * power(2, n - 1)) % MOD;
        return total_sum;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/sum-of-all-sub-sequences-of-a-number3437/1)