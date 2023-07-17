void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        dfs(root->right);
        
        if(root->left){  // Change links : make left subtree attached with root->right & then new root->right with previous root->right  as preorder : root->left->right
            TreeNode *right = root->right;
            root->right = root->left;
            root->left = NULL;             //🟩Dont forget to make left NULL,otherwise 000f error
            while(root->right) root = root->right;
            root->right = right;
        }        
}
