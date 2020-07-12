# https://leetcode.com/problems/two-sum/
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_table={}
        O=[]
        for i, num in enumerate(nums):
            j = target - num
            g = hash_table.get(j)
            if g is not None:
                O.append(g)
                O.append(i)
                break
            else:
                hash_table[num] = i
        return O