class Solution(object):
    def minMoves2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        tam = len( nums )
        nums.sort()
        mediana = nums[tam // 2]
        soma = 0
        for val in nums:
            soma += abs( val - mediana )

        return soma