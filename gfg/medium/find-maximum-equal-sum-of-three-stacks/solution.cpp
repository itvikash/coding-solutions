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