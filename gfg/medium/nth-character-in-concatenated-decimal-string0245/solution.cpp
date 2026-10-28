class Solution {
public:
 char nthCharacter(int n) {
 long long pos = n;
 long long len = 9;
 long long start = 1;
 long long digits = 1;
 while (pos > len * digits) {
pos -= len * digits;
 len *= 10;
 start *= 10;
 digits++;
 }
  long long number = start + (pos - 1) / digits;
 int index = (pos - 1) % digits;
 string s = to_string(number);
 return s[index];
 }
};