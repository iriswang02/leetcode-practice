
/**********************************************************************************
*
* Write a function to find the longest common prefix string amongst an array of strings.
* If there is no common prefix, return an empty string "".
*
* Input: strs = ["flower","flow","flight"]
* Output: "fl"
*
*
**********************************************************************************/

class Solution {

  /*
  *   [Vertical scanning]
  *
  *   Time complexity : O(S), where S is the sum of all characters in all strings.
  *   the best case there are at most n * ⋅minLen comparisons where minLen is the length of the shortest string in the array.
  *
  *   Space complexity : O(1). We only used constant extra space.
  */

public:
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs.size();
        if (n == 0) {
            return "";
        }
        if (n == 1) {
            return strs[0];
        }

        string pivot = strs[0];
        int l = pivot.length();
        string result = "";
        int idx = 0;
        while (idx<l) {
            for (int i=1; i<n; i++) {
                if (strs[i].length() == 0) {
                    return "";
                }
                if (idx >= strs[i].length()) {
                    return result;
                }
                if (pivot[idx] != strs[i][idx]) {
                    return result;
                }
            }
            result += pivot[idx];
            idx += 1;
        }
        return result;
    }
};
