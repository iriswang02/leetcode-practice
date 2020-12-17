
/**********************************************************************************
*
* Given a 32-bit signed integer, reverse digits of an integer.
*
* Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
* For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*
* Input: s = -123
* Output: -321
*
*
**********************************************************************************/

class Solution {

  /*
  *   [Visit by Row]
  *
  *   Time Complexity: O(n). [std::reverse]: Linear in half the distance between first and last: Swaps elements.
  *
  *   Space complexity : O(1).
  */

public:
    int reverse(int x) {

        bool sign = false;
        if (x>=0) {
            if (x < 10) {
                return x;
            }
        } else {
            sign = true;
            x = abs(x);
        }

        string xx = to_string(x);

        ::reverse(xx.begin(), xx.end());

        try {
            x = stoi(xx);
        } catch (exception& e) {
            return 0;
        }

        if (sign == true) {
            x = -x;
        }
        return x;
    }
};
