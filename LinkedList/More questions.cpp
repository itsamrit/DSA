Linked list cycle :-

ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*>s;
        while(head && head->next){
            if(s.find(head)!=s.end()){
                return head;
            }
            s.insert(head);
            head=head->next;
        }
        return NULL;
}
