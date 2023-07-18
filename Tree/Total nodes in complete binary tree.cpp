Tc: 0(height) = o(logn)

int findHeightLeft(TreeNode* node) {
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->left; 
        }
        return hght; 
}

int findHeightRight(TreeNode* node) {
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->right; 
        }
        return hght; 
}

int countNodes(TreeNode* root) {
        if(!root) return 0; 
        
        int lh = findHeightLeft(root); 
        int rh = findHeightRight(root); 
        
        if(lh == rh) return pow(2,lh)-1;   //2^height-1          //In bits u can return (1<<lh) - 1; 
        
        return 1 + countNodes(root->left) + countNodes(root->right);// this condition will be provided 1 or 2 times only so o(h) 

}
