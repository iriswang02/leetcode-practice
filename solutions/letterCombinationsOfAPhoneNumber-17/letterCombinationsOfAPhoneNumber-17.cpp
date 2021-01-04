
/**********************************************************************************
*
* Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
* Return the answer in any order.
*
* Input: digits = "23"
* Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*
*
**********************************************************************************/

class Solution {

  /*
  *   [Backtracking]
  *
  *   Time complexity : O(3^N×4^M) where N is the number of digits in the input that maps to 3 letters (e.g. 2, 3, 4, 5, 6, 8)
  *   and M is the number of digits in the input that maps to 4 letters (e.g. 7, 9), and N+M is the total number digits in the input.
  *
  *   Space complexity : O(3^N×4^M) since one has to keep 3^Nx4^M solutions.
  */

public:
    map<char,vector<char>> phone = {{'2', {'a', 'b', 'c'}},
                                         {'3', {'d', 'e', 'f'}},
                                         {'4', {'g', 'h', 'i'}},
                                         {'5', {'j', 'k', 'l'}},
                                         {'6', {'m', 'n', 'o'}},
                                         {'7', {'p', 'q', 'r', 's'}},
                                         {'8', {'t', 'u', 'v'}},
                                         {'9', {'w', 'x', 'y', 'z'}}};
    vector<string> result;
    vector<string> letterCombinations(string digits) {

        if (digits.length() != 0) {
            backtrack("", digits);
        }
        return result;
    }

    void backtrack(string curr_str, string next_digits) {

        if (next_digits.length() == 0) {
            result.push_back(curr_str);
        } else {

            for (char& letter: phone[next_digits[0]]) {
                curr_str = curr_str + letter;
                backtrack(curr_str, next_digits.substr(1,next_digits.length()));
                curr_str = curr_str.substr(0,curr_str.length()-1);
            }
        }
    }
};
