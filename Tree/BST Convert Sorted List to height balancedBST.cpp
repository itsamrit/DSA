//Convert Sorted linked list i,e inorder linkedlist to height balanced bst

TreeNode* sortedListToBST(ListNode* head) {
        if(!head)  return NULL;
        if(!head->next) return new TreeNode(head->val);
        
        ListNode *slow=head,*fast=head->next;
        while(fast && fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;   
        }
        ListNode *mid=slow->next;
        slow->next=NULL;                         // Breaking the linkedlist into 2 equal halves
        
        TreeNode *root=new TreeNode(mid->val);
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(mid->next);
        return root;
}
