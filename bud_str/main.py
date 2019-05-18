class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len( A ) != len( B ):
            return False
        if A == B:
            return len( set(A) ) < len( A )
        D = []
        for i in range( len(A) ):
            if A[ i ] != B[ i ]:
                D.append( i )
        if len( D ) != 2:
            return False
        front = D[ 0 ]
        back  = D[ 1 ]
        A = list( A )
        B = list( B )
        A[ front ], A[ back ] = A[ back ], A[ front ]
        return A == B

if __name__ == '__main__':
    solution = Solution()
    print( solution.buddyStrings( "ab", "ba" ) )
    print( solution.buddyStrings( "ab", "ab" ) )
    print( solution.buddyStrings( "aa", "aa" ) )
    print( solution.buddyStrings( "aaaaaaabc", "aaaaaaacb" ) )
    print( solution.buddyStrings( "", "aa" ) )
    