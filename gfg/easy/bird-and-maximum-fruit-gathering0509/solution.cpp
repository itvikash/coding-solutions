class Solution {
  public:
    int maxPackages(vector<int>& arr, int totalTime) {
        // code here
        int ans = LLONG_MIN;
        int n = arr.size();
        int sum = 0;
        for(int i=0; i<min(totalTime, n); i++){
            sum += arr[i];
        }
        int r = min(totalTime, n);
        int l = 0;

        while(r < n){
            ans = max(ans, sum);
            sum -= arr[l];
            sum += arr[r];
            r++; l++;
        }
        ans = max(ans, sum);
        return ans;
    }
};