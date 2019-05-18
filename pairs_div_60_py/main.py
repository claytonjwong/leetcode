from typing import List

class Solution:
    def numPairsDivisibleBy60( self, times: List[int] ) -> int:
        C = {}
        for t in times:
            C[ t % 60 ] = 1 + C.get( t % 60, 0 )
        M = C.get(  0, 0 )
        N = C.get( 30, 0 )
        P = M*( M-1 )/2 + N*( N-1 )/2
        for t in range( 1, 30 ):
            P += C.get( t, 0 ) * C.get( 60 - t, 0 )
        return P

if __name__ == '__main__':
    solution = Solution()
    times = [ 30,20,150,100,40 ]
    ans = int( solution.numPairsDivisibleBy60( times ))
    print( ans )