class Solution { 
public: 
 vector<int> parent, sz; 
 int find(int x) { 
 if (parent[x] != x) 
 parent[x] = find(parent[x]); 
 return parent[x]; 
 } 
 long long unite(int a, int b) { 
 a = find(a); 
 b = find(b); 
 if (a == b) return 0; 
 if (sz[a] < sz[b]) 
 swap(a, b); 
 long long ans = 1LL * sz[a] * sz[b]; 
 parent[b] = a; 
 sz[a] += sz[b]; 
 return ans; 
 } 
 vector<int> maximumWeight(int n, vector<vector<int>>& edges,  vector<int>& queries) { 
 sort(edges.begin(), edges.end(),
 [](const vector<int>& a, const vector<int>& b) {  return a[2] < b[2]; 
 }); 
 int q = queries.size(); 
 vector<pair<int, int>> qu; 
 for (int i = 0; i < q; i++) 
 qu.push_back({queries[i], i}); 
 sort(qu.begin(), qu.end()); 
 parent.resize(n + 1); 
 sz.assign(n + 1, 1); 
 for (int i = 1; i <= n; i++) 
 parent[i] = i; 
 vector<int> ans(q); 
 long long cnt = 0; 
 int j = 0; 
 for (auto &p : qu) { 
 int x = p.first; 
 int idx = p.second; 
 while (j < edges.size() && edges[j][2] <= x) {  cnt += unite(edges[j][0], edges[j][1]);  j++; 
 }
 ans[idx] = cnt;  } 
 return ans; 
 } 
};
