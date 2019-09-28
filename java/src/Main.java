public class Main {

    public static class Solution {
        public boolean canThreePartsEqualSum( int[] A ){
            int N = A.length,
                sum = 0,
                K = 0;
            for( int i=0; i < N; ++i )
                sum += A[ i ];
            for( int i=0, cur=0, target=( sum / 3 ); i < N; ++i ){
                cur += A[ i ];
                if( cur == target ){
                    cur = 0;
                    ++K;
                }
            }
            return K == 3;
        }
    }

    public static void main( String[] args ){
        Solution solution = new Solution();
        int[] A = { 3,3,6,5,-2,2,5,1,-9,4 };
        boolean ans = solution.canThreePartsEqualSum( A );
        System.out.println( ans );
    }
}
