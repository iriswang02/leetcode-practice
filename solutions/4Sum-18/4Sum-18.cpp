
/**********************************************************************************
*
* Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target?
* Find all unique quadruplets in the array which gives the sum of target.
*
* Input: nums = [1,0,-1,0,-2,2], target = 0
* Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*
*
**********************************************************************************/

class Solution {

  /*
  *   [Two Pointers]
  *
  *   Time Complexity: O(n^3). We have outer and inner loops, each going through nn elements.
  *   Note that for k > 2, sorting the array does not change the overall time complexity.
  *
  *   Space Complexity: O(n). We need O(k) space for the recursion.
  *   k can be the same as n in the worst case for the generalized algorithm.
  */

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;

        for (int i=0; i<n; i++) {

            vector<vector<int>> tuples = threeSum(nums, i+1, target - nums[i]);
            vector<int> final_tuple(4);
            for (vector<int>& tuple : tuples) {
                final_tuple[0] = nums[i];
                final_tuple[1] = tuple[0];
                final_tuple[2] = tuple[1];
                final_tuple[3] = tuple[2];
                result.push_back(final_tuple);
            }
            while (i < n - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return result;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int start, int target) {

        int n = nums.size();
        vector<vector<int>> result;
        for (int i=start; i<n; i++) {

            vector<vector<int>> tuples = twoSum(nums, i+1, target - nums[i]);
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

    vector <vector<int>> twoSum(vector<int>& nums, int start, int target) {

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
