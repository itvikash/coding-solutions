class Solution {
public:
 int getMinimumDays(string &s, vector<int> &p) {
  int n = s.size();
int bad = 0;
    for (int i = 0; i < n - 1; i++) {
if (s[i] == s[i + 1])
bad++;
}
  if (bad == 0)
return 0;
 vector<int> removed(n, 0);
  for (int day = 0; day < n; day++) {
int x = p[day];
  if (x > 0 && !removed[x - 1] && s[x - 1] == s[x])
bad--;
  if (x < n - 1 && !removed[x + 1] && s[x] == s[x + 1])
bad--;
 removed[x] = 1;
  if (bad == 0)
return day + 1;
 } return n;
 }
};