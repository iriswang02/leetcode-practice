
/**********************************************************************************
*
* Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
* Find all unique triplets in the array which gives the sum of zero.
*
* Input: nums = [-1,0,1,2,-1,-4]
* Output: [[-1,-1,2],[-1,0,1]]
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
  *   Space Complexity: O(n). We need O(k) space for the recursion.
  *   k can be the same as n in the worst case for the generalized algorithm.
  */

public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;

        for (int i=0; i<n; i++) {

            vector<vector<int>> tuples = twoSum(nums, i+1, 0 - nums[i]);
            vector<int> final_tuple(3);
            for (vector<int>& tuple : tuples) {
                final_tuple[0] = nums[i];
                final_tuple[1] = tuple[0];
                final_tuple[2] = tuple[1];
                result.push_back(final_tuple);
            }
            while (i < n - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return result;
    }

    vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {

        int left = start, right = nums.size()-1;
        vector<vector<int>> result;
        while (left < right) {

            int low_val = nums[left], high_val = nums[right];
            int sum = low_val + high_val;
            if (sum < target) {
                while (left < right && nums[left] == low_val) {
                    left++;
                }
            } else if (sum > target) {
                while (left < right && nums[right] == high_val) {
                    right--;
                }
            } else {
                result.push_back({nums[left], nums[right]});
                while (left < right && nums[left] == low_val) {
                    left++;
                }
                while (left < right && nums[right] == high_val) {
                    right--;
                }
            }
        }
        return result;
    }
};
