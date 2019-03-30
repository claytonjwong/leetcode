package com.claytonjwong;

public class Main {

    public static ListNode addTwoNumbers( ListNode a, ListNode b ){
        boolean carry = false;
        ListNode ans = new ListNode( -1 ), tail = ans;
        for(;( a != null || b != null ); a=(( a != null )? a.next : null ), b=(( b != null )? b.next : null ), tail=( tail.next )){
            int sum = (( a != null )? a.val : 0 )
                    + (( b != null )? b.val : 0 )
                    + (( carry     )?     1 : 0 );
            carry = ( 9 < sum );
            tail.next = new ListNode( sum % 10 );
        }
        tail.next = ( carry )? new ListNode( 1 ) : null;
        return ans.next;
    }

    public static void main(String[] args) {
        ListNode a = new ListNode( 9 );
        a.next = new ListNode( 9 );
        a.next.next = new ListNode( 9 );
        ListNode b = new ListNode( 1 );
        ListNode ans = addTwoNumbers( a, b );
        return;
    }
}
