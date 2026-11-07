#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> generateUsernames(vector<string>& arr) {
        unordered_set<string> used(arr.begin(), arr.end());
        unordered_map<string, int> counts;
        unordered_set<string> assigned;

        vector<string> result;
        result.reserve(arr.size());

        for (const string& name : arr) {
            if (assigned.find(name) == assigned.end()) {
                assigned.insert(name);
                result.push_back(name);
            } else {
                int k = counts.count(name) ? counts[name] : 1;
                string candidate = name + to_string(k);

                while (used.find(candidate) != used.end()) {
                    k++;
                    candidate = name + to_string(k);
                }

                used.insert(candidate);
                counts[name] = k + 1;
                result.push_back(candidate);
            }
        }

        return result;
    }
};