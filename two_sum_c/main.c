#include <stdio.h>
#include <stdlib.h>

struct List_t {
    char val;

    struct List_t* next;
};
typedef struct List_t List;
typedef List* HList;
int find( HList* map, int val ){
    char str[ 10 ];
    sprintf( str, "%d", val );
    HList head = map[ str[ 0 ] ];
    int i=1;
    for( ; i )
}
void insert( HList* map, int val ){
    find( map, val );
}

int* twoSum( int* A, int N, int T ){
    int* ans = malloc( 2 * sizeof( int ));
    HList map[ 10 ];
    for( int i=0; i < 10; ++i )
        map[ i ] = NULL;
    for( int i=0, j=0; i < N; ++i ){
        int x = A[ i ],
            y = T - x;
        if(( j = find( map, y )) > 0 ){
            ans[ 0 ] = i;
            ans[ 1 ] = j;
        }
        insert( map, x );
    }

    return 0;
}

int main() {

    return 0;
}