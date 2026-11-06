class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxVet = max( nums )
        tam = len( nums )
        soma = sum( nums )
        soma = maxVet * tam - soma

        return soma