
/**********************************************************************************
*
* Given a string s, find the length of the longest substring without repeating characters.
*
* Input: s = "abcabcbb"
* Output: 3
*
*
**********************************************************************************/

class Solution {

  /*
  *   [Sliding Window]
  *
  *   Time complexity : O(2n)=O(n). In the worst case each character will be visited twice by i and j.
  *
  *   Space complexity : O(min(m,n)). Same as the previous approach.
  *   We need O(k) space for the sliding window, where k is the size of the Set.
  *   The size of the Set is upper bounded by the size of the string n and the size of the charset/alphabet m.
  */

public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> window;
        int n = s.length();

        int left = 0;
        int right = 0;
        int valid = 0;
        char c;
        int result = 0;
        while (right < n) {

            c = s[right];
            right++;
            window[c]++;
            while (window[c] > 1) {

                window[s[left]]--;
                left++;
            }
            result = max(result, right-left);
        }
        return result;
    }
};
