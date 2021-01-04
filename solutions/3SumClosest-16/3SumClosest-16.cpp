
/**********************************************************************************
*
* Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.
* Return the sum of the three integers. You may assume that each input would have exactly one solution.
*
* Input: nums = [-1,2,1,-4], target = 1
* Output: 2
*
*
**********************************************************************************/

class Solution {

  /*
  *   [Two Pointers]
  *
  *   Time Complexity: O(n^2). We have outer and inner loops, each going through nn elements.
  *   Sorting the array takes O(nlogn), so overall complexity is O(nlogn+n^2).
  *   This is asymptotically equivalent to O(n^2).
  *
  *   Space Complexity: from O(logn) to O(n), depending on the implementation of the sorting algorithm.
  */

public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX, sz = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < sz && diff != 0; ++i) {
            int lo = i + 1, hi = sz - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (abs(target - sum) < abs(diff))
                    diff = target - sum;
                if (sum < target)
                    ++lo;
                else
                    --hi;
            }
        }
        return target - diff;
    }
};
