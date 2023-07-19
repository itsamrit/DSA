TreeNode* dfs(TreeNode*root,TreeNode*p, TreeNode*q){
        if(!root)return NULL;
        if(root==p || root==q)return root;   //🟩considering p to be root.IF p is intial root then other must be some child or grandchild of it.so ans will be root
        
        TreeNode* left=dfs(root->left,p,q);
        TreeNode* right=dfs(root->right,p,q);
        if(left && right)return root;
        if(left)return left;            //🟩considering p to be root.IF p is intial root then other must be some child or grandchild of it.so ans will be root
        if(right)return right;        
        return NULL;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
}
