class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        menor = min( nums )
        movs = 0
        for val in nums:
            movs += val - menor

        return movs