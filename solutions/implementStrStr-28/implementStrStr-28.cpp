
/**********************************************************************************
*
* Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*
* Input: haystack = "hello", needle = "ll"
* Output: 2
*
*
**********************************************************************************/

class Solution {

  /*
  *   [For Loop]
  *
  *   Time complexity : O(mn). m and n is the length of two strings.
  *
  *   Space Complexity: O(1).
  */

public:
    int strStr(string haystack, string needle) {
        
        size_t n1 = needle.size();
        size_t n2 = haystack.size();
        if (n1 == 0) {
            return 0;
        }
        
        if (n1 > n2) {
            return -1;
        }
        
        size_t idx = 0;
        for (int idx=0; idx<n2-n1+1; idx++) {
            
            if (needle[0] == haystack[idx]) {
                if (needleExist(needle, haystack, idx+1, n1, n2)) {
                    return idx;
                }
            }
        }
        return -1;
    }
                
    bool needleExist(string needle, string haystack, int idx, int n1, int n2) {
        
        for (int i=1; i<n1; i++, idx++) {
            
            if (idx>=n2 || needle[i] != haystack[idx]) {
                return false;
            }
        }
        return true;
    }
};