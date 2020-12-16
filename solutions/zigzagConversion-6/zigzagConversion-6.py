class Solution:
    def convert(self, s: str, numRows: int) -> str:

        n = len(s)
        if numRows == 1:
            return s

        stride = 2*(numRows - 1)
        result = ""
        for i in range(numRows):
            j=0
            while j+i<n:
                result += s[j+i]
                if i!=0 and i!=numRows-1 and j+stride-i<n:
                    result += s[j+stride-i]
                j += stride
        return result
