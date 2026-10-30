class Solution {
public:
vector<vector<int>> formCoils(int n) {
int m = 4 * n;
int total = m * m;
vector<int> a, b;
int top = 0, bottom = m - 1;
int left = 0, right = m - 1;
while (top <= bottom && left <= right) {

for (int i = top; i <= bottom; i++)
a.push_back(i * m + left + 1);
for (int j = left + 1; j < right; j++)
a.push_back(bottom * m + j + 1);

for (int i = bottom - 1; i > top; i--)
a.push_back(i * m + right - 1 + 1);

for (int j = right - 2; j > left + 1; j--)
a.push_back((top + 1) * m + j + 1);
top += 2;
bottom -= 2;
left += 2;
right -= 2;
}
for (int x : a)
b.push_back(total + 1 - x);
return {a, b};
}
};