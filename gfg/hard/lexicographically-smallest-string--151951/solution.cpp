class Solution {
public:
string lexiString(string s) {
int n = s.size();
string t = s + s;
int i = 0, j = 1, k = 0;
while (i < n && j < n && k < n) {
if (t[i + k] == t[j + k]) {
k++;
}
else if (t[i + k] > t[j + k]) {
i = i + k + 1;
if (i == j)
i++;
k = 0;
}
else {
j = j + k + 1;
if (i == j)
j++;
k = 0;
}
}
int start = min(i, j);
return t.substr(start, n);
}
};