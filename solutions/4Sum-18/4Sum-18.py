class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:

        nums.sort()
        n = len(nums)
        result = []

        i=0
        while i<n:
            tuples = self.threeSum(nums, i+1, target-nums[i])
            for tuple in tuples:
                result.append([nums[i]]+tuple)
            while i<n-1 and nums[i] == nums[i+1]:
                i += 1
            i += 1

        return result


    def threeSum(self, nums, start, target):

        n = len(nums)
        result = []

        i=start
        while i<n:
            tuples = self.twoSum(nums, i+1, target-nums[i])
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
