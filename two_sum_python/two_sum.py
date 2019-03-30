# python3

from typing import List

class Solution:
    def twoSum(self, A: List[int], T: int) -> List[int]:
        M = {}
        for i, x in enumerate( A ):
            y = T - x
            if y in M:
                j = M[ y ]
                return [ i, j ]
            M[ x ] = i
        return []

if __name__ == '__main__':
    solution = Solution()
    A = [ 2, 7, 11 ,15 ]
    T = 9
    ans = solution.twoSum( A, T )
    for x in ans:
        print( x, end=" " )
