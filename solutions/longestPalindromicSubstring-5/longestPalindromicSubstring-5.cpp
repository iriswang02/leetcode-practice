
/**********************************************************************************
*
* Given a string s, return the longest palindromic substring in s.
*
* Input: s = "babad"
* Output: "bab"
* Note: "aba" is also a valid answer.
*
*
**********************************************************************************/

class Solution {

  /*
  *   [Expand Around Center]
  *
  *   Time complexity : O(n^2). Since expanding a palindrome around its center could take O(n) time, the overall complexity is O(n^2).
  *
  *   Space complexity : O(1).
  */

public:
    string longestPalindrome(string s) {

        int n = s.length();
        if (n == 1) {
            return s;
        }

        int start=0, end=0, l;
        for (int i=0; i<n; i++) {
            l = max(palindrome(s, n, i-1, i+1), palindrome(s, n, i, i+1));
            if ((end-start) < l) {
                start = i-(l-1)/2;
                end = start+l;
            }
        }
        return s.substr(start,end-start);
    }

    int palindrome(string s, int n, int i, int j) {

        while (i>=0 && j<= n-1 && s[i] == s[j]) {
            i--;
            j++;
        }
        return j-i-1;
    }
};
