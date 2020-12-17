
/**********************************************************************************
*
* Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
*
* Input: nums1 = [1,3], nums2 = [2]
* Output: 2.00000
*
*
**********************************************************************************/

class Solution {

  /*
  *   [Recursive Approach]
  *
  *   Time complexity : O(log(min(m,n))). Binary search on the shorter array.
  *
  *   Space complexity : O(1). We only need constant memory to store local varaibles.
  */

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 <= n2) {
            return helper(nums1, n1, nums2, n2);
        } else {
            return helper(nums2, n2, nums1, n1);
        }

    }

    double helper(vector<int>& nums1, int n1, vector<int>& nums2, int n2) {

        int partition_size = (n1 + n2 + 1)/2;
        int left = 0;
        int right = n1;
        int mid1, mid2;
        double result;

        while (left <= right) {

            mid1 = left + (right - left)/2;
            mid2 = partition_size - mid1;

            if (mid1 < n1 && mid2 > 0 && nums1[mid1] < nums2[mid2-1]) { // searching on right
                left = mid1 + 1;
            } else if (mid1 > 0 && mid2 < n2 && nums2[mid2] < nums1[mid1-1]) { // searching on left
                right = mid1-1;
            } else { // perfectly partitioned
                if (mid1 == 0) { // elements from nums1[] in the first half is an empty set.
                    result = nums2[mid2-1];
                } else if (mid2 == 0) {  // elements from nums2[] in the first half is an empty set.
                    result = nums1[mid1-1];
                } else {
                    result = max(nums1[mid1-1], nums2[mid2-1]);
                }
                break;
            }
        }

        if ((n1 + n2)%2 == 1) {
            return result;
        } else {
            if (mid1 == n1) {  // elements from nums1[] in the second half is an empty set.
                return (result + nums2[mid2])/2;
            }
            if (mid2 == n2) {  // elements from nums2[] in the second half is an empty set.
                return (result + nums1[mid1])/2;
            }
        }
        return (result + min(nums1[mid1], nums2[mid2]))/2;
    }
};
