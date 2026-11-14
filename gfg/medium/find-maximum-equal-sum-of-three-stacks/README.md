# Max Equal Sum in 3 Stacks

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given three stacks  **s1**,  **s2**, and  **s3**, represented by arrays where the first element of each array represents the top of the corresponding stack.

Find the maximum possible equal sum(sum of all elements) of all three stacks by removing zero or more elements from the top of each stack.

If it is not possible to make the sum of all three stacks equal, return  **0**.

 **Examples:** 

```
Input: s1 = [3, 2, 1, 1, 1], s2 = [4, 3, 2], s3 = [2, 5, 4, 1]
Output: 5
Explanation: Remove 3 from s1, 4 from s2, and 2, 5 from s3. The remaining sums of all three stacks are equal to 5.

```

```
Input: s1 = [4,7], s2 = [10], s3 = [1,2,3]
Output: 0
Explanation: It is not possible to make the sums of all three stacks equal by removing elements from their tops.

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-14T06:29:41.765Z  

```cpp
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maxEqualSum(vector<int> &S1, vector<int> &S2, vector<int> &S3) {
        int N1 = S1.size();
        int N2 = S2.size();
        int N3 = S3.size();

        long long sum1 = accumulate(S1.begin(), S1.end(), 0LL);
        long long sum2 = accumulate(S2.begin(), S2.end(), 0LL);
        long long sum3 = accumulate(S3.begin(), S3.end(), 0LL);

        int i = 0, j = 0, k = 0;

        while (i < N1 && j < N2 && k < N3) {
            if (sum1 == sum2 && sum2 == sum3) {
                return sum1;
            }

            if (sum1 >= sum2 && sum1 >= sum3) {
                sum1 -= S1[i++];
            } else if (sum2 >= sum1 && sum2 >= sum3) {
                sum2 -= S2[j++];
            } else {
                sum3 -= S3[k++];
            }
        }

        return 0;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/find-maximum-equal-sum-of-three-stacks/1)