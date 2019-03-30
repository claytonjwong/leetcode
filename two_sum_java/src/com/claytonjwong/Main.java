package com.claytonjwong;

import java.util.HashMap;
import java.util.Collections;

public class Main {

    public static int[] twoSum( int[] A, int T ) {
        HashMap< Integer,Integer > M = new HashMap<>();
        for( int i=0; i < A.length; ++i ){
            int x = A[ i ],
                y = T - x;
            if( M.containsKey( y )){
                int j = M.get( y );
                return new int[] { i, j };
            }
            M.put( x, i );
        }
        return new int[]{};
    }
    public static void main(String[] args) {
        int[] A = { 2, 7, 11, 15 };
        int T = 9;
        int[] ans = twoSum( A, T );
        for( int i=0; i < ans.length; ++i )
            System.out.print( ans[ i ] + " " );
    }
}
