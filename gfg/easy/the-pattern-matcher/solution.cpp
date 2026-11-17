class Solution {
  public:
    bool findPattern(string& s) {
        int n = s.length();
        int i = 0;

        while (i < n) {
            int countX = 0;
            while (i < n && s[i] == 'x') {
                countX++;
                i++;
            }

            if (countX == 0) {
                return false;
            }

            int countY = 0;
            while (i < n && s[i] == 'y') {
                countY++;
                i++;
            }

            if (countX != countY) {
                return false;
            }
        }

        return true;
    }
};