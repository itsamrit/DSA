✅Always recursion intutive very hard


def dfs(head, k):
    temp = head
    for i in range(0, k):  # Loop to check whether there are k elements or not. If not, don't reverse.
        if not temp:
            return head
        temp = temp.next

    curr, prev, nxt = head, None, None
    for i in range(k):
        nxt = curr.next
        curr.next = prev
        prev = curr
        curr = nxt
    head.next = dfs(curr, k)
    return prev
