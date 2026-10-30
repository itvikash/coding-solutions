class Solution {
public:
bool balancePan(int a, int b) {
long long B = b;
long long A = a;
while(B > 0){
long long r = B % A;
B /= A;
if(r == 0 || r == 1) continue;
if(r == A-1){
B += 1;
continue;
}
return false;
}
return true;
}
};