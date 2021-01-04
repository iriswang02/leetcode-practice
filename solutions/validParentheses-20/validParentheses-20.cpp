
/**********************************************************************************
*
* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
*
* Input: s = "([)]"
* Output: false
*
*
**********************************************************************************/

class Solution {

  /*
  *   [Stacks]
  *
  *   Time complexity : O(n) because we simply traverse the given string one character at a time
  *   and push and pop operations on a stack take O(1) time.
  *
  *   Space complexity : O(n) as we push all opening brackets onto the stack and in the worst case,
  *   we will end up pushing all the brackets onto the stack.
  */

public:
    bool isValid(string s) {

        int n = s.length();
        if (n%2 == 1) {
            return false;
        }

        map<char,char> mp = {{'(', ')'},
                             {'[', ']'},
                             {'{', '}'}};

        stack<char> left_brackets;
        for (int i=0; i<n; i++) {

            if (mp.find(s[i]) != mp.end()) {
                left_brackets.push(s[i]);
            } else {
                if (left_brackets.empty()) {
                    return false;
                } else if (s[i] != mp[left_brackets.top()]) {
                    return false;
                } else {
                    left_brackets.pop();
                }
            }
        }

        if (!left_brackets.empty()) {
            return false;
        } else {
            return true;
        }
    }
};
