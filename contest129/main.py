# python3

# class Solution:
#     def canThreePartsEqualSum( self, A ) -> bool:
#         target = sum( A ) // 3
#         cur = 0
#         K = 0
#         for x in A:
#             cur += x
#             if cur == target:
#                 cur = 0
#                 K += 1
#         return K == 3
#
# if __name__ == '__main__':
#     A = [ 0,2,1,-6,6,-7,9,1,2,0,1 ]
#     solution = Solution()
#     ans = solution.canThreePartsEqualSum( A )
#     print( ans )


class Solution:
    def smallestRepunitDivByK(self, K: int) -> int:
        N = 1
        for i in range( 1, 100000 ):
            if N % K == 0:
                return i
            N = ( N * 10 + 1 ) % K
        return -1

if __name__ == '__main__':
    solution = Solution()
    ans = solution.smallestRepunitDivByK( 19927 )
    print( ans )


