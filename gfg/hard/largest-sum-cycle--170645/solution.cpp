class Solution {
public:
int largestSumCycle(vector<int>& edge) {
int n = edge.size();
vector<int> vis(n, 0);
long long ans = -1;

for (int i = 0; i < n; i++) {
if (vis[i]) continue;

int cur = i;

while (cur != -1 && vis[cur] == 0) {
vis[cur] = 1;
cur = edge[cur];
}

if (cur != -1 && vis[cur] == 1) {
long long sum = 0;
int temp = cur;

do {
sum += temp;
temp = edge[temp];
} while (temp != cur);

ans = max(ans, sum);
}

cur = i;

while (cur != -1 && vis[cur] == 1) {
vis[cur] = 2;
cur = edge[cur];
}
}

return (int)ans;
}
};