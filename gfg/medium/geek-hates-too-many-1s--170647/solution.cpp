class Solution {
public:
int maxValue(int n) {
for (int i = 28; i >= 0; i--) {
if ((n & (1 << i)) &&
(n & (1 << (i + 1))) &&
(n & (1 << (i + 2)))) {
n &= ~(1 << i);
}
}
return n;
}
};