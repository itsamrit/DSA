// You just need to compare the current node. So no dp required. ✅✅✅✅

Tc: o(n)    Sc:o(n) auxiliary space 

// Symmetric Tree : Check whether a tree has same mirror image as its original image i,e, Compare there left & right subtrees are equal or not
// Identical/Same Trees : Check whether 2 or more trees are exact same or not i,e check whether left of both are equal or not & right of both are equal or not

bool ans;
void dfs(TreeNode* p,TreeNode*q){
        if(!p && !q)return;
        if(!p || !q){ans=false;return;}
        if(p->val!=q->val){
            ans=false;
        }
        dfs(p->left,q->left);      // For symmetricity : p->left,q->right
        dfs(p->right,q->right);    // For symmetricity : p->right,q->left
}
    
bool identical (TreeNode* p, TreeNode* q) {  
                                  // For symmetricity : if(!(root->left) && !(root->right))return true;
                                  // For symmetricity : if(!(root->left) || !(root->right))return false;
        ans=true;
        dfs(p,q);
        return ans;
}



//🟩o(n^2) compare if subtree is part a tree leaves must be same 
    bool dfs(TreeNode* root, TreeNode* sub){
        if(!root && !sub)return true;
        if(!root || !sub )return false;
        if(root->val != sub->val)return false;
        bool left=dfs(root->left,sub->left);
        bool right=dfs(root->right,sub->right);
        if(left && right)return true;
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if(!root && !sub)return true;
        if(!root || !sub)return false;
        if(dfs(root,sub) || isSubtree(root->left, sub) || isSubtree(root->right,sub))return true;
        return false;
    }
