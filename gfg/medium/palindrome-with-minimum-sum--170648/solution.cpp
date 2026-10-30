class Solution {
public:
int minimumSum(string s) {
int n = s.size();

for (int i = 0; i < n / 2; i++) {
int j = n - 1 - i;

if (s[i] != '?' && s[j] != '?' && s[i] != s[j])
return -1;

if (s[i] == '?' && s[j] != '?')
s[i] = s[j];
else if (s[j] == '?' && s[i] != '?')
s[j] = s[i];
}

int i = 0;

while (i < n) {
if (s[i] != '?') {
i++;
continue;
}

int j = i;
while (j < n && s[j] == '?')
j++;

char left = (i > 0) ? s[i - 1] : '?';
char right = (j < n) ? s[j] : '?';

char c = 'a';

if (left != '?' && right != '?')
c = (left < right) ? left : right;
else if (left != '?')
c = left;
else if (right != '?')
c = right;

for (int k = i; k < j; k++)
s[k] = c;

i = j;
}

int ans = 0;

for (int k = 1; k < n; k++)
ans += abs(s[k] - s[k - 1]);

return ans;
}
};