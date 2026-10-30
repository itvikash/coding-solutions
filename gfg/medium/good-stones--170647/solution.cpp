class Solution {
public:
int goodIndices(vector<int>& arr) {
int n = arr.size();
vector<int> dp(n, 0);

function<bool(int)> dfs = [&](int i) {
if (i < 0 || i >= n)
return true;

if (dp[i] != 0)
return dp[i] == 1;

if (arr[i] == 0) {
dp[i] = -1;
return false;
}

dp[i] = -1;
int next = i + arr[i];

if (dfs(next)) {
dp[i] = 1;
return true;
}

return false;
};

int ans = 0;

for (int i = 0; i < n; i++) {
if (dfs(i))
ans++;
}

return ans;
}
};