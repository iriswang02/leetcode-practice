class Solution:
    def isValid(self, s: str) -> bool:

        n = len(s)
        if n%2 == 1:
            return False

        mp = {"(": ")",
              "[": "]",
              "{": "}"}
        left_brackets = []
        for i in range(n):

            if s[i] in mp.keys():
                left_brackets.append(s[i])
            else:
                if left_brackets == []:
                    return False
                elif s[i] != mp[left_brackets[-1]]:
                    return False
                else:
                    left_brackets.pop()

        if left_brackets == []:
            return True
        else:
            return False

            
