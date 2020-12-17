class Solution:
    def myAtoi(self, s: str) -> int:

        n = len(s)
        if n == 0:
            return 0;

        sign = 1
        result = 0
        curr = 0
        while curr < n and s[curr] == ' ':
            curr += 1

        if curr < n and (s[curr] == '+' or s[curr] == '-'):
            sign = -1 if s[curr] == '-' else 1;
            curr += 1

        while curr < n and s[curr] >= '0' and s[curr] <= '9':

            result = result*10 + (int(s[curr]) - int('0'))
            if result > 2147483647 or result < -2147483648:
                return 2147483647 if sign == 1 else -2147483648
            curr += 1

        return result*sign
