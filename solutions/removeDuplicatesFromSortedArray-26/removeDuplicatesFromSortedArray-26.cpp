
/**********************************************************************************
*
* Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
*
* Input: nums = [1,1,2]
* Output: 2, nums = [1,2]
*
*
**********************************************************************************/

class Solution {

  /*
  *   [Two Pointers]
  *
  *   Time complexity : O(n). Assume that n is the length of array. Each of i and j traverses at most n steps.
  *
  *   Space Complexity: O(1).
  */

public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        int left = 0;
        int right = 0;
        
        while(right < n){
            
            if (nums[right] != nums[left]) {
                left++;
                nums[left] = nums[right];
            }
            right++;
        }
        return left+1;
    }
};