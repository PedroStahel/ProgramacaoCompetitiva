class Solution(object):
    def findTheDistanceValue(self, arr1, arr2, d):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :type d: int
        :rtype: int
        """
        
        cont = 0
        for val1 in arr1:
            sign = 0
            for val2 in arr2:
                if abs( val1 - val2 ) <= d:
                    sign = 1
                    break
            if sign == 0:
                cont += 1

        return cont