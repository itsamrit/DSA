def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    cur = head
    next = None
    prev = None
    while(cur):
        next = cur.next
        cur.next = prev
        prev= cur
        cur = next
    return prev
// cur occurs in after a gap in sequence
