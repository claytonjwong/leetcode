#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode( int val ) : val{ val }, next{ nullptr } {}
};

class Solution {
public:
    ListNode* addTwoNumbers( ListNode* a, ListNode* b, bool carry=false ){
        auto ans = new ListNode( -1 ), tail = ans;
        for(;( a || b ); a=( a? a->next : nullptr ), b=( b? b->next : nullptr ), tail=( tail->next )){
            auto sum = ( a? a->val : 0 )
                     + ( b? b->val : 0 )
                     + ( carry?  1 : 0 );
            carry = ( 9 < sum );
            tail->next = new ListNode( sum % 10 );
        }
        tail->next = carry? new ListNode( 1 ) : nullptr;
        return ans->next;
    }
};

int main() {
    Solution solution;
    ListNode* a = new ListNode( 9 );
    a->next = new ListNode( 9 );
    a->next->next = new ListNode( 9 );
    ListNode* b = new ListNode( 1 );
    auto ans = solution.addTwoNumbers( a, b );
    return 0;
}