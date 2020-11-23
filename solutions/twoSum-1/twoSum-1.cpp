
/**********************************************************************************
*
* Given an array of integers, find two numbers such that they add up to a specific target number.
*
* The function twoSum should return indices of the two numbers such that they add up to the target,
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2)
* are not zero-based.
*
* You may assume that each input would have exactly one solution.
*
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
*
*
**********************************************************************************/


class Solution {
public:

    /*
     *   [Two-pass Hash Table]
     *
     *   Time complexity : O(n). We traverse the list containing n elements exactly twice.
     *   Since the hash table reduces the look up time to O(1)O(1), the time complexity is O(n).
     *
     *   Space complexity : O(n). The extra space required depends on the number of items stored in the hash table,
     *   which stores exactly nn elements.
     */

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>hashmap;
        vector<int> result;

        for(int i=0; i<nums.size(); i++) {
            hashmap.emplace(nums[i],i);
        }
        for(int i=0; i<nums.size(); i++) {
            int numberToFind = target - nums[i];

            if(hashmap.find(numberToFind) != hashmap.end() && hashmap[numberToFind] != i) {
                result.push_back(i);
                result.push_back(hashmap[numberToFind]);
                break;
            }
        }
        return result;
    }
};
