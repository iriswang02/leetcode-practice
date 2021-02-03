
/**********************************************************************************
*
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*
* Input: n = 3
* Output: ["((()))","(()())","(())()","()(())","()()()"]
*
*
**********************************************************************************/

class Solution {

  /*
  *   [Backtracking]
  *
  *   Time complexity : O(4^n/sqrt(n)). Each valid sequence has at most n steps during the backtracking procedure.
  *
  *   Space Complexity: O(4^n/sqrt(n)). We only used constant extra space.
  */

public:
    
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        
        string track;
        backtrack(n, n, track);
        return result;
    }
    
    void backtrack(int left, int right, string track) {
        
        // base case
        if (left > right) {
            return;
        }
        if (left < 0 || right < 0) {
            return;
        }
        if (left == 0 && right == 0) {
            result.push_back(track);
            return;
        }
        
        track.push_back('(');
        backtrack(left-1, right, track);
        track.pop_back();
        
        track.push_back(')');
        backtrack(left, right-1, track);
        track.pop_back();

    }
    
};