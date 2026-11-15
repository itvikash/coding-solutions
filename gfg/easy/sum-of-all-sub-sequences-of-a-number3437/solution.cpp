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