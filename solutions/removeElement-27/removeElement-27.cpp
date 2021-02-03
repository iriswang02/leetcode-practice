
/**********************************************************************************
*
* Given an array nums and a value val, remove all instances of that value in-place and return the new length.
*
* Input: nums = [3,2,2,3], val = 3
* Output: 2, nums = [2,2]
*
*
**********************************************************************************/

class Solution {

  /*
  *   [Two Pointers]
  *
  *   Time complexity : O(n). Assume the array has a total of n elements, both i and j traverse at most 2n steps.
  *
  *   Space Complexity: O(1).
  */

public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        
        int slow = 0;
        int fast = 0;
        
        while (fast < n) {
            
            if(nums[fast] != val) {
                
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};