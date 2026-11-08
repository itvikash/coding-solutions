class Solution {
  public:
    long long minTime(int n, int s1, int s2) {
        long long low = 1;
        long long high = 1LL * min(s1, s2) * n;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

           
            long long totalScanned = (mid / s1) + (mid / s2);

            if (totalScanned >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};