class ListNode:
    def __init__( self, x ):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, a: ListNode, b: ListNode) -> ListNode:
        carry = False
        ans = tail = ListNode( -1 )
        while a or b:
            sum =  a.val if a else 0
            sum += b.val if b else 0
            sum += 1 if carry else 0
            carry = 9 < sum
            tail.next = ListNode( sum % 10 )
            a = a.next if a else None
            b = b.next if b else None
            tail = tail.next
        tail.next = ListNode( 1 ) if carry else None
        return ans.next

if __name__ == '__main__':
    solution = Solution()
    a = ListNode( 9 )
    a.next = ListNode( 9 )
    a.next.next = ListNode( 9 )
    b = ListNode( 1 )
    ans = solution.addTwoNumbers( a, b )
    print( "ok" )