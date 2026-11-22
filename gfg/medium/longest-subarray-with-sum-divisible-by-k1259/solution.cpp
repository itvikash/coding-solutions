class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        unordered_map<int, int> remMap;
        long long prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];
            int rem = ((prefixSum % k) + k) % k;

            if (rem == 0) {
                maxLen = i + 1;
            } else if (remMap.find(rem) != remMap.end()) {
                maxLen = max(maxLen, i - remMap[rem]);
            } else {
                remMap[rem] = i;
            }
        }

        return maxLen;
    }
};