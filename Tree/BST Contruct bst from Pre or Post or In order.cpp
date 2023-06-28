// Traversal :
// Tc : o(n) SC; o(n) auxiliary space.Use this as striver has use recursive solution
// Use intuitive/non recursive solution only in searching in bst
// No questions on Inorder to bst 
// 🟩root->val=NULL means root->val=0 not null . So dont return root->val =NULL, return NULL
        
TreeNode* dfs(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) return NULL; // In postorder : i==-1 || A[i]<bound  // 🟩root->val=NULL means root->val=0 not null . So dont return root->val =NULL, return NULL;
        TreeNode* root = new TreeNode(A[i++]);          // In postorder : A[i--]
        root->left = dfs(A, i, root->val);
        root->right = dfs(A, i, bound);
        return root;
}

TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;                                     //In postorder : i=A.size()-1;
        return dfs(A, i, INT_MAX);                     //IN postorder : INT_MIN
}


// Construct HEIGHt balanced tree from inorder Linked List i,e sorted linked list :-    
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
