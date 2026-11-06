class Solution {
public:
    long long int countBT(int h) {
        if (h == 0 || h == 1) return 1;

        long long int MOD = 1e9 + 7;
        long long int dp0 = 1; // dp[i-2]
        long long int dp1 = 1; // dp[i-1]
        long long int dp2;    // dp[i]

        for (int i = 2; i <= h; i++) {
            dp2 = (dp1 * (dp1 + 2 * dp0)) % MOD;
            dp0 = dp1;
            dp1 = dp2;
        }

        return dp1;
    }
};