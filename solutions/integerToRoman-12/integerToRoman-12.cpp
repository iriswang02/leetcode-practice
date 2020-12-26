
/**********************************************************************************
*
* Given an integer, convert it to a roman numeral.
*
* Input: num = 1994
* Output: "MCMXCIV"
*
*
**********************************************************************************/

class Solution {

  /*
  *   [If Statement]
  *
  *   Time Complexity: O(n). n is the number of symbols of the output roman numeral.
  *
  *   Space complexity : O(1). Constant space is used.
  */

public:
    string intToRoman(int num) {

        string result = "";
        while (num!=0) {
            if (num/1000 >= 1) {
                result += "M";
                num = num-1000;
            } else if (num/900 >= 1) {
                result += "CM";
                num = num-900;
            } else if (num/500 >= 1) {
                result += "D";
                num = num-500;
            } else if (num/400 >= 1) {
                result += "CD";
                num = num-400;
            } else if (num/100 >= 1) {
                result += "C";
                num = num-100;
            } else if (num/90 >= 1) {
                result += "XC";
                num = num-90;
            } else if (num/50 >= 1) {
                result += "L";
                num = num-50;
            } else if (num/40 >= 1) {
                result += "XL";
                num = num-40;
            } else if (num/10 >= 1) {
                result += "X";
                num = num-10;
            } else if (num/9 >= 1) {
                result += "IX";
                num = num-9;
            } else if (num/5 >= 1) {
                result += "V";
                num = num-5;
            } else if (num/4 >= 1) {
                result += "IV";
                num = num-4;
            } else {
                result += "I";
                num = num-1;
            }
        }
        return result;
    }
};
