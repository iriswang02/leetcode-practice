
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
  *   [Scan from left to right]
  *
  *   Time Complexity: O(n). Here, N is the length of string str. We perform only one iteration over string str.
  *
  *   Space complexity : O(1). We only need constant memory to store local varaibles.
  */

public:
  int myAtoi(string s) {

      int n = s.length();
      string str_result = "";
      int result = 0;
      bool got_number = false;
      bool got_sign = false;
      bool neg_sign = false;
      string limit_neg = "2147483648";
      string limit_pos = "2147483647";
      for (int i=0; i<n; i++) {

          if ( (s[i] > '9' || s[i] < '0') && s[i] != '-' && s[i] != ' ' && s[i] != '+') { // not a number or sign or white space
              break;
          } else {
              if (s[i] <= '9' && s[i] >= '0') { // a number
                  got_number = true;
                  str_result += s[i];
              } else {
                  if (got_number || got_sign) {
                      break;
                  } else {
                      if (s[i] == '-' || s[i] == '+') {
                          got_sign = true;
                          if (s[i] == '-') {
                              neg_sign = true;
                          }
                      } else {
                          continue;
                      }
                  }
              }
          }
      }

      while (str_result[0] == '0') {
          str_result = str_result.substr(1);
      }

      if (str_result.length() != 0) {
         if (neg_sign) {
              if ( (str_result >= limit_neg && str_result.length() == limit_neg.length()) || str_result.length() > limit_neg.length()) {
                  result = INT_MIN;
              } else {
                  result = -stoi(str_result);
              }
          } else {
              if ( (str_result >= limit_pos && str_result.length() == limit_pos.length()) || str_result.length() > limit_pos.length()) {
                  result = INT_MAX;
              } else {
                  result = stoi(str_result);
              }
          }
      }
      return result;
  }
};
