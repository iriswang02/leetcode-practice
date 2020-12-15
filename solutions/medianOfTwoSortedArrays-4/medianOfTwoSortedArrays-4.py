class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        m,n = len(nums1), len(nums2)

        def helper(nums1, m, nums2, n):

            left = 0
            right = m
            partition_size = (m+n+1)//2

            while left<=right:
                i = round(left + (right-left)/2)
                j = partition_size - i

                if i<m and j>0 and nums2[j-1] > nums1[i]:
                    left = i+1
                elif i>0 and j<n and nums2[j] < nums1[i-1]:
                    right = i-1
                else: # perfectly partitioned

                    if i == 0:
                        result = nums2[j-1]
                    elif j == 0:
                        result = nums1[i-1]
                    else:
                        result = max(nums1[i-1], nums2[j-1])
                    break

            if (m+n)%2 == 1:
                return result*1.0
            else:
                if i == m:
                    return (result+nums2[j])/2.0
                elif j == n:
                    return (result+nums1[i])/2.0
                else:
                    return (result + min(nums1[i], nums2[j]))/2.0

        if m<=n:
            return helper(nums1, m, nums2, n)
        else:
            return helper(nums2, n, nums1, m)
