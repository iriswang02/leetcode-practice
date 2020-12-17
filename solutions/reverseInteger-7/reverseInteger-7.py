class Solution:
    def reverse(self, x: int) -> int:

        if x>-10 and x<10:
            return x

        sign = 1
        if x<0:
            sign = -1
            x = abs(x)

        result = 0
        while x>=10:
            result = result*10 + (x%10)
            x = x//10
        result = result*10 + x

        if result >= 2147483647 or result <= -2147483648:
            return 0
        return result*sign
