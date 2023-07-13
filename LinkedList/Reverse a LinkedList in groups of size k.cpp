✅Always recursion intutive very hard

ListNode* rec(ListNode* head, int k) {
        ListNode* temp = head;
        for(int i = 0; i < k; i++){
            if(temp == nullptr) return head;
            temp = temp->next;
        }
	
        ListNode* curr = head,*prev = nullptr,*nxt;   //NEXT IS DIRECTLLY INTIALixed inside loop
        for(int i = 0; i < k; i++){
            nxt = curr->next;  
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
}
