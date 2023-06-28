// tc:o(n) sc other than auxiliary space:o(1)  Auxiliary space: o(n) 
// We can further do morris traversal to reduce auxiliary stack space to o(1)

TreeNode*first;
TreeNode*second;

void dfs(TreeNode*root, TreeNode*&pre){
        if(!root)return;
        dfs(root->left,pre);
        if(!first && root->val<pre->val){
            first=pre;
        }
        if(first && root->val<pre->val){    
            second=root;
        }
        pre=root;
        dfs(root->right,pre);
}
    
void recoverTree(TreeNode* root) {
        TreeNode*pre =new TreeNode(INT_MIN);
        dfs(root,pre);
        swap(first->val,second->val);
}
