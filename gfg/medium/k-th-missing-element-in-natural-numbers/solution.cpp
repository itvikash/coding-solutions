class Solution {
  public:
    int findKthSmall(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        for (int x : arr) {
            if (x <= k) {
                k++;
            } else {
                break;
            }
        }
        return k;
    }
};