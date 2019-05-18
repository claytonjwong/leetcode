import java.util.List;
import java.util.ArrayList;

public class Main {

    public static List<Boolean> prefixesDivBy5( int[] bits ){
        List< Boolean > ans = new ArrayList<>();
        int N = 0;
        for( int bit: bits ){
            N <<= 1;
            N |= bit;
            N %= 5;
            ans.add( N == 0 );
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println("Hello World!");
    }
}
