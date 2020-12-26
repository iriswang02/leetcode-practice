class Solution:
    def romanToInt(self, s: str) -> int:

        n = len(s)
        result = 0
        prev = ''
        for i in range(n):

            if s[i] == 'I':
                prev = 'I'
                result += 1

            elif s[i] == 'V':
                if prev == 'I':
                    result += 3
                else:
                    result += 5
                prev = 'V'

            elif s[i] == 'X':
                if prev == 'I':
                    result += 8
                else:
                    result += 10
                prev = 'X'

            elif s[i] == 'L':
                if prev == 'X':
                    result += 30
                else:
                    result += 50
                prev = 'L'

            elif s[i] == 'C':
                if prev == 'X':
                    result += 80
                else:
                    result += 100
                prev = 'C'

            elif s[i] == 'D':
                if prev == 'C':
                    result += 300
                else:
                    result += 500
                prev = 'D'

            elif s[i] == 'M':
                if prev == 'C':
                    result += 800
                else:
                    result += 1000
                prev = 'M'

        return result
