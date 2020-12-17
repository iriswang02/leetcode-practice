class Solution:
    def isPalindrome(self, x: int) -> bool:

        if x<0:
            return False

        if x>=0 and x<=9:
            return True

        result = 0
        temp = x
        while temp>=10 :
            result = result*10 + temp%10
            temp = temp//10
        result = result*10 + temp%10

        if result == x:
            return True
        else:
            return False
