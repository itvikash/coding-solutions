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