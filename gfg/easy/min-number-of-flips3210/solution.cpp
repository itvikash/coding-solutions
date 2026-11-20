#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int flipsStart0 = 0; // target: "010101..."
        int flipsStart1 = 0; // target: "101010..."

        for (int i = 0; i < (int)s.size(); ++i) {
            char expected0 = (i % 2 == 0) ? '0' : '1';
            char expected1 = (i % 2 == 0) ? '1' : '0';

            if (s[i] != expected0) ++flipsStart0;
            if (s[i] != expected1) ++flipsStart1;
        }

        return min(flipsStart0, flipsStart1);
    }
};