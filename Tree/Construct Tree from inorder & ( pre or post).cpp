//Prerequisite : inorder = left,root,right ,        pre= root,left,right          post = left,right,root
//tc=o(n)
    TreeNode* dfs(vector<int>&postorder, int preStart, int preEnd, vector<int>&inorder, int inStart,int inEnd,map<int,int>&m){
        if(preStart>preEnd || inStart>inEnd)return NULL;
        TreeNode* root=new TreeNode(postorder[preEnd]);//
        int inRoot=m[postorder[preEnd]];//
        int numsLeft=inRoot-inStart;
        root->left=dfs(postorder,preStart,preStart+numsLeft-1,inorder,inStart,inRoot-1,m);//
        root->right=dfs(postorder,preStart+numsLeft,preEnd-1,inorder,inRoot+1,inEnd,m);//
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return dfs(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,m);
    }




    TreeNode* dfs(vector<int>&postorder, int preStart, int preEnd, vector<int>&inorder, int inStart,int inEnd,map<int,int>&m){
        if(preStart>preEnd || inStart>inEnd)return NULL;
        TreeNode* root=new TreeNode(postorder[preEnd]);//
        int inRoot=m[postorder[preEnd]];//
        int numsLeft=inRoot-inStart;
        root->left=dfs(postorder,preStart,preStart+numsLeft-1,inorder,inStart,inRoot-1,m);//
        root->right=dfs(postorder,preStart+numsLeft,preEnd-1,inorder,inRoot+1,inEnd,m);//
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return dfs(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,m);
    }
