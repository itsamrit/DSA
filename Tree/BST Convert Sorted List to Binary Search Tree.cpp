TreeNode* sortedListToBST(ListNode* head) {
        if(!head)  return NULL;
        if(!head->next) return new TreeNode(head->val);
        
        ListNode *slow=head,*fast=head->next;
        while(fast && fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;   
        }
        ListNode *mid=slow->next;
        slow->next=NULL;
        
        TreeNode *root=new TreeNode(mid->val);
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(mid->next);
        return root;
}
