class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        my_dict = {}
        result = []

        for idx, item in enumerate(nums):
	        if item not in my_dict:
		        my_dict[item] = [idx]
	        else:
		        my_dict[item].append(idx)

        for key in my_dict:
            if (target - key) in my_dict:
                if (target - key) == key and (len(my_dict[key]) > 1):
                    result += my_dict[key]
                elif (target - key) != key:
                    result += (my_dict[key] + my_dict[target - key])
        return list(set(result))