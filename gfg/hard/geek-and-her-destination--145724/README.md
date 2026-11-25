# Geek's Destination with Special Jump

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Geek starts at position  **0**  on the positive X-axis and needs to reach or pass position  **d**  on the positive X-axis.

Geek normally follows a repeating movement pattern:

- Move forward by a units, taking a seconds.
- Move backward by b units, taking b seconds.

Geek also has a special jump that moves him exactly  **j**  units forward in 1 second. He can use it at any time, even in the middle of a forward or backward movement, and the journey ends immediately after the jump.

Given five integers  **a**,  **b**,  **d**,  **l**, and  **r**. For every integer j in the range [l, r], find the minimum time required for Geek to reach or pass position d. He may either use the special jump or reach the destination using normal movement alone, whichever takes less time.

Return the sum of the minimum times for all jump lengths from l to r. Since, the answer can be large, return modulo 109 + 7. 

 **Note:** Each jump length is considered independently.

 **Examples:** 

```
Input: a = 2, b = 1, d = 5, l = 3, r = 4
Output: 5
Explanation: 
For j = 3, Geek moves 2 units forward, then takes a jump of 3 units to reach the destination. The minimum time required is 3 seconds.
For j = 4, Geek moves 1 unit forward, then takes a jump of 4 units to reach the destination. The minimum time required is 2 seconds.
Total sum for the range [l, r] = 3 + 2 = 5.
```

```
Input: a = 4, b = 2, d = 8, l = 2, r = 4
Output: 26
Explanation:
For j = 2, Geek moves 4 units forward, then 2 units backward. She then moves 4 units forward again and takes a jump of 2 units to reach the destination. The minimum time required is 11 seconds.
For j = 3, Geek moves 4 units forward, then 2 units backward. She then moves 3 units forward and takes a jump of 3 units to reach the destination. The minimum time required is 10 seconds.
For j = 4, Geek moves 4 units forward, then takes a jump of 4 units to reach the destination. The minimum time required is 5 seconds.
Total sum for the range [l, r] = 11 + 10 + 5 = 26.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-25T04:10:54.283Z  

```cpp
class Solution {
    static constexpr long long MOD = 1000000007LL;

    long long sumFloor(long long L, long long R, long long D) {
        if (R < 0 || L > R) return 0;
        if (L < 0) L = 0;

        long long qL = L / D, rL = L % D;
        long long qR = R / D, rR = R % D;

        if (qL == qR) {
            return (R - L + 1) * qL;
        }

        __int128 ans = 0;
        ans += (__int128)(D - rL) * qL;
        ans += (__int128)(rR + 1) * qR;

        long long first = qL + 1;
        long long last = qR - 1;
        if (first <= last) {
            __int128 count = (__int128)last - first + 1;
            __int128 sumQ = count * ((__int128)first + last) / 2;
            ans += (__int128)D * sumQ;
        }
        return (long long)ans;
    }

    long long prefixSum(long long N, long long a, long long b, long long d) {
        if (N <= 0) return 0;

        long long D = a - b;
        __int128 top = (__int128)d - a + D - 1;
        long long L = (long long)(top - N);
        long long R = (long long)(top - 1);
        long long sumK = sumFloor(L, R, D);

        __int128 n128 = N;
        __int128 d128 = d;
        long long sumConst = (n128 % MOD) * ((d128 + 1) % MOD) % MOD;
        long long sumJ = (n128 * (n128 + 1) / 2) % MOD;
        long long part1 = (sumConst - sumJ + MOD) % MOD;

        long long part2 = (((__int128)2 * b) % MOD) * ((__int128)sumK % MOD) % MOD;

        return (part1 + part2) % MOD;
    }

public:
    int minTime(int a, int b, int d, int l, int r) {
        long long ans = (prefixSum(r, a, b, d) - prefixSum((long long)l - 1, a, b, d)) % MOD;
        if (ans < 0) ans += MOD;
        return (int)ans;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/geek-and-her-destination--145724/1)