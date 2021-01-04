class Solution:
    def letterCombinations(self, digits: str) -> List[str]:

        phone = {'2': ['a', 'b', 'c'],
             '3': ['d', 'e', 'f'],
             '4': ['g', 'h', 'i'],
             '5': ['j', 'k', 'l'],
             '6': ['m', 'n', 'o'],
             '7': ['p', 'q', 'r', 's'],
             '8': ['t', 'u', 'v'],
             '9': ['w', 'x', 'y', 'z']}

        def backtrack(curr_str, next_digits):

            if len(next_digits) == 0:
                result.append(curr_str)
            else:
                for letter in phone[next_digits[0]]:
                    curr_str = curr_str + letter
                    backtrack(curr_str, next_digits[1:])
                    curr_str = curr_str[:-1]

        result = []
        if digits:
            backtrack("", digits)
        return result
