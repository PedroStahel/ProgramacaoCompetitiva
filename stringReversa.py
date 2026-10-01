class Solution(object):
    def reverseDegree(self, s):
        """
        :type s: str
        :rtype: int
        """
        soma = 0
        max = len( s )
        for i in range( max ):
            soma += ( -ord( s[i] ) + 123 ) * ( i + 1 ) # 97 + 26

        return soma 