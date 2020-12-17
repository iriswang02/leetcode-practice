
/**********************************************************************************
*
* Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where:
*
* '.' Matches any single character.​​​​
* '*' Matches zero or more of the preceding element.
*
* The matching should cover the entire input string (not partial).
*
* Input: s = "aab", p = "c*a*b"
* Output: true
*
*
**********************************************************************************/

class Solution {

  /*
  *   [Dynamic Programming]
  *
  *   Time Complexity: Let T, P be the lengths of the text and the pattern respectively.
  *   The work for every call to dp(i, j) for i=0, ... ,T; j=0, ... ,P is done once, and it is O(1) work.
  *   Hence, the time complexity is O(TP).
  *
  *   Space complexity : The only memory we use is the O(TP) boolean entries in our cache. Hence, the space complexity is O(TP).
  */

public:
    bool isMatch(string s, string p) {

        int n1 = s.length();
        int n2 = p.length();

        map<pair<int,int>, bool> memo;

        return dp(0,0,s,p,memo);

    }

    bool dp(int i, int j, string s, string p, map<pair<int,int>, bool>& memo) {

        pair<int,int> key = pair<int,int>(i,j);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        bool ans;
        if (j>=p.length()) {
            return (i == s.length());
        } else {

            bool first_match = ( i<s.length() && (s.at(i) == p.at(j) || p.at(j) == '.' ) ); // the first char

            if( j<p.length()-1 && p.at(j+1) == '*' ) { // the second char

                ans = ( dp(i,j+2,s,p,memo) || (first_match && dp(i+1,j,s,p,memo)) ); // (zero) || (one or more)

            } else {
                ans = first_match && dp(i+1,j+1,s,p,memo);
            }

            memo[key] = ans;
            cout << key.first << "," << key.second << endl;
            return memo[key];
        }
    }

};
