class Solution {
  public:
    vector<int> findPairs(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, pair<int, int>> sumMap;
        vector<int> ans = {n, n, n, n};
        bool found = false;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = arr[i] + arr[j];

                if (sumMap.find(sum) == sumMap.end()) {
                    sumMap[sum] = {i, j};
                } else {
                    pair<int, int> p = sumMap[sum];
                    int a = p.first, b = p.second;

                    if (a != i && a != j && b != i && b != j) {
                        vector<int> curr;
                        if (make_pair(a, b) < make_pair(i, j)) {
                            curr = {a, b, i, j};
                        } else {
                            curr = {i, j, a, b};
                        }

                        if (!found || curr < ans) {
                            ans = curr;
                            found = true;
                        }
                    }
                }
            }
        }

        return found ? ans : vector<int>{-1, -1, -1, -1};
    }
};