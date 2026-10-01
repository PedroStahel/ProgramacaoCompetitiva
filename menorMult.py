class Solution(object):
    def missingMultiple(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
        max = len( nums )
        for i in range( max ):
            if not( k * ( i + 1 ) in nums ):
                return k * ( i + 1 )

        return k * ( max + 1 )