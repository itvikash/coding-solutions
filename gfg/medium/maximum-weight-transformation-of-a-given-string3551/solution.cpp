class Solution {
public:
int getMaxWeight(string s) {
int n = s.size();
vector<int> dp(n + 1, 0);

for (int i = n - 1; i >= 0; i--) {
dp[i] = 1 + dp[i + 1];

if (i + 1 < n) {
int pairWeight = (s[i] == s[i + 1]) ? 3 : 4;
dp[i] = max(dp[i], pairWeight + dp[i + 2]);
}
}

return dp[0];
}
};