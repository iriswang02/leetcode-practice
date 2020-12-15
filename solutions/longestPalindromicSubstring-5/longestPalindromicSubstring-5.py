class Solution:
    def longestPalindrome(self, s: str) -> str:

        n = len(s)
        if n == 1:
            return s

        self.max_length = 0
        self.out_s = s[0]

        for idx in range(n):
            self.palindrome(s, n, idx-1, idx+1)
            self.palindrome(s, n, idx, idx+1)

        return self.out_s

    def palindrome(self, s, n, i, j):

        while i>=0 and j<n and s[i]==s[j]:
            if j-i+1 > self.max_length:
                self.max_length = j-i+1
                self.out_s = s[i:j+1]
            i -= 1
            j += 1
