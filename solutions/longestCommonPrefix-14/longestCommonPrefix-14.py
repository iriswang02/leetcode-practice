class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:

        n = len(strs)
        if n == 0:
            return ""
        if n == 1:
            return strs[0]

        pivot = strs[0]
        l = len(pivot)
        result = ""
        idx = 0
        while idx<l:
            for i in range(1, n):
                if len(strs[i]) == 0:
                    return ""
                if idx >= len(strs[i]):
                    return result
                if pivot[idx] != strs[i][idx]:
                    return result
            result += pivot[idx]
            idx += 1

        return result
