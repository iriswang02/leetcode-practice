
/**********************************************************************************
*
* Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
*
* Input: s = 121
* Output: true
*
*
**********************************************************************************/

class Solution {

  /*
  *   [Revert half of the number]
  *
  *   Time complexity : O(log10(n)). We divided the input by 10 for every iteration, so the time complexity is O(log10(n)).
  *
  *   Space complexity : O(1).
  */

public:
    bool isPalindrome(int x) {

        if (x<0 || (x%10 == 0 && x!=0)) {
            return false;
        }

        int result = 0;
        while (x > result) {
            result = result*10 + x%10;
            x /= 10;
        }
        return x==result || x == result/10;
    }
};
