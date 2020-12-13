class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        n = len(s)
        if n == 0:
            return 0
        window = {}
        start = 0
        result = 1

        for i in range(n):
            c = s[i]
            if c in window:
                start = max(start, window[c]+1)
            result = max(result, i-start+1)
            window[c] = i
        return result
