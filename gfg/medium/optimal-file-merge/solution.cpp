class Solution {
  public:
    int minComputation(vector<int> &files) {
        multiset<int> s;
        int n = files.size();
        for(int i=0; i<n; i++){
            s.insert(files[i]);
        }
        int ans = 0;
        while(s.size() != 1){
            auto it = next(s.begin(),1);
            int val = *s.begin() + *it;
            ans += val;

            s.erase(s.begin());
            s.erase(s.begin());
            s.insert(val);
        }
        return ans;
    }
};