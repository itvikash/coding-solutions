#include <climits>
class Solution {
  public:
    int minDiff(int k, vector<int> &arr) {
        int n = arr.size();
        vector<int> prefMax(n+1,-1), prefMin(n+1, INT_MAX);
        vector<int> suffMax(n+1,-1), suffMin(n+1, INT_MAX);

        for(int i=0; i<n; i++){
            prefMax[i+1] = max(prefMax[i], arr[i]);
            prefMin[i+1] = min(prefMin[i], arr[i]);
        }

        for(int i=n-1; i>=0; i--){
            suffMax[i] = max(suffMax[i+1], arr[i]);
            suffMin[i] = min(suffMin[i+1], arr[i]);
        }

        int l = 0, r = k;
        int ans = INT_MAX;
        while(r<=n){
            int maxi = max(prefMax[l], suffMax[r]);
            int mini = min(prefMin[l], suffMin[r]);

            ans = min(ans, maxi - mini);
            r++, l++;
        }
        return ans;
    }
};