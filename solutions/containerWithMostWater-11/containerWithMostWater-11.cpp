
/**********************************************************************************
*
* Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
* n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0).
* Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
*
* Input: height = [1,8,6,2,5,4,8,3,7]
* Output: 49
*
*
**********************************************************************************/

class Solution {

  /*
  *   [Two Pointer]
  *
  *   Time complexity : O(n). Single pass.
  *
  *   Space complexity : O(1). Constant space is used.
  */

public:
    int maxArea(vector<int>& height) {

        int n = height.size();
        int left = 0, right = n-1;
        int result = 0;

        while (left<right) {

            result = max(result, min(height[left], height[right])*(right-left));
            if (height[left] < height[right]) {
                left += 1;
            } else {
                right -= 1;
            }
        }
        return result;
    }
};
