class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        
        n = len(nums)
        if n==0:
            return 0
        left = 0
        right = 0
        
        while right<n:
            
            if nums[right] != nums[left]:
                left += 1
                nums[left] = nums[right]
            right += 1
        
        return left+1