
/**********************************************************************************
*
* Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
*
* Input: dividend = 10, divisor = 3
* Output: 3
*
*
**********************************************************************************/

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if (dividend == divisor) {
            return 1;
        } 
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (divisor == INT_MIN) {
            return 0;
        }
        if (divisor == -1) {
            return -dividend;
        }
        if (divisor == 1) {
            return dividend;
        }
        
        
        int res = 0;
        if (divisor<0) {
            divisor = -divisor;
            if (dividend>0) {
                dividend -= divisor;
                while (dividend>=0) {
                    dividend -= divisor;
                    res--;
                }
            } else {
                dividend += divisor;
                while (dividend<=0) {
                    dividend += divisor;
                    res++;
                }
            }
        } else {
            if (dividend>0) {
                dividend -= divisor;
                while (dividend>=0) {
                    dividend -= divisor;
                    res++;
                }
            } else {
                dividend += divisor;
                while (dividend<=0) {
                    dividend += divisor;
                    res--;
                }
            }
        }
        return res;
    }
};