class Solution:
    def intToRoman(self, num: int) -> str:

        result = ""
        while num!=0:
            if num/1000 >= 1:
                result += "M"
                num = num-1000
            elif num/900 >= 1:
                result += "CM"
                num = num-900
            elif num/500 >= 1:
                result += "D"
                num = num-500
            elif num/400 >= 1:
                result += "CD"
                num = num-400
            elif num/100 >= 1:
                result += "C"
                num = num-100
            elif num/90 >= 1:
                result += "XC"
                num = num-90
            elif num/50 >= 1:
                result += "L"
                num = num-50
            elif num/40 >= 1:
                result += "XL"
                num = num-40
            elif num/10 >= 1:
                result += "X"
                num = num-10
            elif num/9 >= 1:
                result += "IX"
                num = num-9
            elif num/5 >= 1:
                result += "V"
                num = num-5
            elif num/4 >= 1:
                result += "IV"
                num = num-4
            else:
                result += "I"
                num = num-1
        return result
