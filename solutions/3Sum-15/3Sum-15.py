class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        nums.sort()
        n = len(nums)
        result = []

        i=0
        while i<n:
            print(i)
            tuples = self.twoSum(nums, i+1, 0-nums[i])
            for tuple in tuples:
                result.append([nums[i]]+tuple)
            while i<n-1 and nums[i] == nums[i+1]:
                i += 1
            i += 1

        return result

    def twoSum(self, nums, start, target):

        left = start
        right = len(nums)-1
        result = []
        while left<right:

            low_val, high_val = nums[left], nums[right]
            sum = low_val + high_val
            if sum<target:
                while left<right and nums[left] == low_val:
                    left += 1
            elif sum>target:
                while left<right and nums[right] == high_val:
                    right -= 1
            else:
                result.append([nums[left], nums[right]])
                while left<right and nums[left] == low_val:
                    left += 1
                while left<right and nums[right] == high_val:
                    right -= 1

        return result
