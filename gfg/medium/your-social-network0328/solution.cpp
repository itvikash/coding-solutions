class Solution {
public:
vector<vector<int>> socialNetwork(vector<int>& arr) {
vector<vector<int>> ans;
int n = arr.size() + 1;
for (int i = 2; i <= n; i++) {
int cur = i;
int dist = 0;
vector<vector<int>> temp;
while (cur != 1) {
cur = arr[cur - 2];
dist++;
temp.push_back({cur, dist});
}
reverse(temp.begin(), temp.end());
for (auto x : temp)
ans.push_back({i, x[0], x[1]});
}
return ans;
}
};