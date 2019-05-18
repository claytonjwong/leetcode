package main

import "fmt"

func prefixesDivBy5( bits []int ) []bool {
	var ans []bool;
	N := 0
	for _, bit := range bits {
		N = (( N << 1 ) + bit ) % 5;
		ans = append( ans, N == 0 );
	}
	return ans;
}

func main() {
	//var bits []int;
	bits := []int{ 0,1,1,1,1,1 };
	ans := prefixesDivBy5( bits );
	fmt.Printf( "%v", ans );
}
