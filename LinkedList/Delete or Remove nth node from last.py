    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        headd = ListNode()  # Dummy node to handle edge cases   ✅✅ANY PROCESS REQUIRING DELETION OR CHANGINg LINKS// To avoid edge case  while checking loop for while(node->next) not required for while(node)  :if only 1 node in linked list
        headd.next = head
        fast = headd
        slow = headd

        # Move fast pointer n steps ahead
        for i in range(0,n):
            fast = fast.next

        # Move both pointers until fast reaches the end  // reaching the node to remove 
        while fast.next:
            fast = fast.next
            slow = slow.next

        # Remove the nth node from the end
        temp = slow.next  #optional 
        slow.next = slow.next.next
        del temp   #optional 

        return headd.next       #// To avoid edge case : if only 1 node in linked list

