class Solution:
    def subsequenceSum(self, s: str) -> int:
        MOD = 1000000007
        sum_digits = sum(int(c) for c in s) % MOD
        n = len(s)
        total_sum = (sum_digits * pow(2, n - 1, MOD)) % MOD
        return total_sum