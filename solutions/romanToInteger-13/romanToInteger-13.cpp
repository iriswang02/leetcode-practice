
/**********************************************************************************
*
* Given a roman numeral, convert it to an integer.
*
* Input: s = "MCMXCIV"
* Output: 1994
*
*
**********************************************************************************/

class Solution {

    /*
    *   [If Statement]
    *
    *   Time Complexity: O(n). Since every symbol is only visited once.
    *
    *   Space complexity: O(1). We only need constant memory to store local varaibles.
    */

public:
    int romanToInt(string s) {

        int n = s.length();
        int result = 0;
        char prev;
        for (int i=0; i<n; i++) {

            if (s[i] == 'I') {
                prev = 'I';
                result += 1;
            } else if (s[i] == 'V') {
                if (prev == 'I') {
                    result += 3;
                } else {
                    result += 5;
                }
                prev = 'V';
            } else if (s[i] == 'X') {
                if (prev == 'I') {
                    result += 8;
                } else {
                    result += 10;
                }
                prev = 'X';
            } else if (s[i] == 'L') {
                if (prev == 'X') {
                    result += 30;
                } else {
                    result += 50;
                }
                prev = 'L';
            } else if (s[i] == 'C') {
                if (prev == 'X') {
                    result += 80;
                } else {
                    result += 100;
                }
                prev = 'C';
            } else if (s[i] == 'D') {
                if (prev == 'C') {
                    result += 300;
                } else {
                    result += 500;
                }
                prev = 'D';
            } else if (s[i] == 'M') {
                if (prev == 'C') {
                    result += 800;
                } else {
                    result += 1000;
                }
                prev = 'M';
            }
        }
        return result;
    }
};
