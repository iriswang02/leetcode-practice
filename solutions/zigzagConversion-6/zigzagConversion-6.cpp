
/**********************************************************************************
*
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
*
* P   A   H   N
* A P L S I I G
* Y   I   R
*
* And then read line by line: "PAHNAPLSIIGYIR"
*
* Input: s = "PAYPALISHIRING", numRows = 3
* Output: "PAHNAPLSIIGYIR"
*
*
**********************************************************************************/

class Solution {

  /*
  *   [Visit by Row]
  *
  *   Time Complexity: O(n), where n==len(s). Each index is visited once.
  *
  *   Space complexity : O(n). For the cpp implementation, O(1) if return string is not considered extra space.
  */

public:
    string convert(string s, int numRows) {

        int n = s.length();
        if (numRows == 1) {
            return s;
        }

        string result = "";
        int stride = 2*(numRows-1);
        for (int i=0; i<numRows; i++) {
            for (int j=0; j+i<n; j += stride) {
                result += s[j+i];
                if (i!=0 && i!=(numRows-1) && j+stride-i<n) {
                    result+= s[j+stride-i];
                }
            }
        }
        return result;
    }
};
