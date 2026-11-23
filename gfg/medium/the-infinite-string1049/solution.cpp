class Solution {
  public:
    char posInfinite(string &s, int pos) {
        long long n = s.size();
        vector<long long> lengths = {n};
        int step = 1;

        while (lengths.back() < pos) {
            long long next_len = 2 * lengths.back() + step;
            lengths.push_back(next_len);
            step++;
        }

        long long p = pos;
        for (int i = (int)lengths.size() - 1; i >= 1; i--) {
            long long prev_len = lengths[i - 1];
            int mid_dollars = i;

            if (p <= prev_len) {
                continue;
            } else if (p <= prev_len + mid_dollars) {
                return '$';
            } else {
                long long offset = p - (prev_len + mid_dollars);
                p = prev_len - offset + 1;
            }
        }

        return s[p - 1];
    }
};