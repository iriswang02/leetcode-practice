class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:

        nums.sort()
        n = len(nums)
        result = 10e4

        i=0
        while i<n:

            left, right = i+1, n-1
            while left<right:
                low_val, high_val = nums[left], nums[right]
                sum = low_val + high_val + nums[i]
                if sum<target:
                    while left<right and nums[left] == low_val:
                        left += 1
                elif sum>target:
                    while left<right and nums[right] == high_val:
                        right -= 1
                else:
                    return target
                    while left<right and nums[left] == low_val:
                        left += 1
                    while left<right and nums[right] == high_val:
                        right -= 1

                if abs(sum-target)<abs(result-target):
                    result = sum

            while i<n-1 and nums[i] == nums[i+1]:
                i += 1
            i += 1

        return result
