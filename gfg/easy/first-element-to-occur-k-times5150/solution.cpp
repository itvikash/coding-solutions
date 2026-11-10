#include <vector>
#include <unordered_map>

class Solution {
public:
    int firstElementKTime(std::vector<int>& arr, int k) {
        std::unordered_map<int, int> counts;

        for (int num : arr) {
            counts[num]++;
            if (counts[num] == k) {
                return num;
            }
        }

        return -1;
    }
};