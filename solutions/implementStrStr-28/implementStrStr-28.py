class Solution:
    def strStr(self, haystack: str, needle: str) -> int:

        n1 = len(needle)
        n2 = len(haystack)
        if n1==0:
            return 0
        
        for start in range(n2-n1+1):
            
            i,j=start,0
            while haystack[i]==needle[j]:
                j+=1
                i+=1
                if j==n1:
                    return start
      
        return -1