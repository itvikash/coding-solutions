class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int n = arr.size();
        int minLen = n + 1;
        long long currSum = 0;
        int start = 0;

        for (int end = 0; end < n; end++) {
            currSum += arr[end];

            while (currSum > x) {
                minLen = min(minLen, end - start + 1);
                currSum -= arr[start];
                start++;
            }
        }

        return (minLen == n + 1) ? 0 : minLen;
    }

    int smallestSubWithSum(vector<int>& arr, int x) {
        return smallestSubWithSum(x, arr);
    }
};