#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode List;
typedef List* HList;
HList createNode( int val ){
    HList node = malloc( sizeof( List ));
    node->val = val;
    node->next = NULL;
    return node;
}
HList addTwoNumbers( HList a, HList b ){
    int carry = 0;
    HList ans = createNode( -1 ), tail = ans;
    for(;( a || b ); a=( a? a->next : NULL ), b=( b? b->next : NULL ), tail=( tail->next )){
        int sum = ( a? a->val : 0 )
                + ( b? b->val : 0 )
                + ( carry?  1 : 0 );
        carry = ( 9 < sum );
        tail->next = createNode( sum % 10 );
    }
    tail->next = ( carry )? createNode( 1 ) : NULL;
    return ans->next;
}

int main() {
    HList a = createNode( 9 );
    a->next = createNode( 9 );
    a->next->next = createNode( 9 );
    HList b = createNode( 1 );
    HList ans = addTwoNumbers( a, b );
    return 0;
}

//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode( int val ) : val{ val }, next{ nullptr } {}
//};
//
//class Solution {
//    public:
//    ListNode* addTwoNumbers( ListNode* first, ListNode* second, bool carry=false ){
//        auto ans = new ListNode( -1 ), tail = ans;
//        for( auto a{ first  }, b{ second }; ( a || b ); a=a?( a->next : nullptr ), b=b?( b->next : nullptr ), tail=( tail->next )){
//            auto sum = ( a? a->val : 0 )
//                       + ( b? b->val : 0 )
//                       + ( carry? 1  : 0 );
//            carry = ( 9 < sum );
//            tail->next = new ListNode( sum % 10 );
//        }
//        tail->next = carry? new ListNode( 1 ) : nullptr;
//        return ans->next;
//    }
//};
//
//int main() {
//    Solution solution;
//    ListNode* a = new ListNode( 9 );
//    a->next = new ListNode( 9 );
//    a->next->next = new ListNode( 9 );
//    ListNode* b = new ListNode( 1 );
//    auto ans = solution.addTwoNumbers( a, b );
//    return 0;
//}