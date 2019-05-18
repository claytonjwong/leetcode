class Solution:
    def prefixesDivBy5( self, bits: List[int] ) -> List[bool]:
        ans = []
        N = 0
        for bit in bits:
            N = (( N << 1 ) + bit ) % 5
            ans.append( N == 0 )
        return ans
