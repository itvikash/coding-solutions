class Solution {
public:
int maximumSubarray(vector<int>& arr) {
int normal = arr[0];
int square = arr[0] * arr[0];

int ans = max(normal, square);

for (int i = 1; i < arr.size(); i++) {
int x = arr[i];

int newSquare = max({
x * x,
normal + x * x,
square + x
});

normal = max(x, normal + x);
square = newSquare;

ans = max(ans, max(normal, square));
}

return ans;
}
};