#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCount(string &s, int k) {
        unordered_map<char, int> group_counts;
        int n = s.length();

        for (int i = 0; i < n; ) {
            char curr = s[i];
            int j = i;
            while (j < n && s[j] == curr) {
                j++;
            }
            group_counts[curr]++;
            i = j;
        }

        int ans = 0;
        for (const auto& pair : group_counts) {
            if (pair.second == k) {
                ans++;
            }
        }

        return ans;
    }
};