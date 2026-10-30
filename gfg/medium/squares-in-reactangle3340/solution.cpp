class Solution {
public:
int minSquares(int n, int m) {
int ans = 0;

while (n > 0 && m > 0) {
if (n < m) {
int temp = n;
n = m;
m = temp;
}

ans += n / m;
n = n % m;
}

return ans;
}
};