// No auxiliary space is used unlike searching using recursion which takes auxiliary space o(height) & if tree is squessed then worst case o(n)
// Time complexity = o(height) = o(logn) because height = log(nodes) in average bst except squessed tree where height=nodes
TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
                if(root->val==val) break;
                else if(root->val>val)root=root->left;  //For ceil : ceil=root->val; root=root->left;     
                                                        //For floor : root=root->left;
                else root=root->right;                  //For ceil : root=root->left
                                                        //for floor : floor=root->val ; root=root->right;
                
        }
        return root;
}







Q; Given a bst .Find succesor of given element according to its inorder traversal.
//Searching : tc:o(h)  sc: o(1) 
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = NULL;
        while (root) {
            if (p->val >= root->val)
                root = root->right;
            else {
                successor = root;
                root = root->left;
            }
        }
        return successor;
}


