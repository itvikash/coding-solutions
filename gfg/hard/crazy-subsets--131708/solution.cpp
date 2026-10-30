class Solution {
  public:
    int cntSubsets(vector<int> &arr, int l, int r) {
        int n = arr.size();
        long long MOD = 1e9 + 7;

        vector<long long> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> freq(r + 1, 0);
        for (int x : arr) {
            if (x <= r) {
                freq[x]++;
            }
        }

        long long ans = 0;
        long long running_ways = 1;
        int pref = 0;

        for (int M = 0; M <= r; M++) {
            pref += freq[M];
            int C = n - pref;

            if (M >= l) {
                long long ways = (running_ways * pow2[C]) % MOD;
                ans = (ans + ways) % MOD;
            }

            long long ways_to_pick_M = (pow2[freq[M]] - 1 + MOD) % MOD;
            running_ways = (running_ways * ways_to_pick_M) % MOD;

            if (running_ways == 0) { break; }
        }

        return ans;
    }
};