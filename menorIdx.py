class Solution(object):
    def smallestIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        max = len( nums )
        for i in range( max ):
            soma = 0
            while nums[i] != 0:
                soma += nums[i] % 10
                nums[i] //= 10
            if i == soma:
                return i
    
        return -1