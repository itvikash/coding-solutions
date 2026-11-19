class Solution {
  public:
    void sortIt(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            bool a_odd = (a % 2 != 0);
            bool b_odd = (b % 2 != 0);

            if (a_odd != b_odd) {
                return a_odd;
            }
            if (a_odd) {
                return a > b;
            }
            return a < b;
        });
    }
};