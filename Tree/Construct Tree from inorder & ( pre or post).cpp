//Prerequisite : inorder = left,root,right ,        pre= root,left,right          post = left,right,root
//tc=o(n)
     #define Node TreeNode
    Node* solve(vector<int>&in, vector<int>&pre, int & index,int inorderStart,int inorderEnd, int n,map<int,int>&m){
        if(index>=n || inorderStart>inorderEnd) return NULL;
        int element=pre[index++];
        Node* root=new Node(element);
        int position=m[element];
        
        root->left=solve(in, pre, index, inorderStart,position-1,n,m);
        root->right= solve(in,pre, index, position+1,inorderEnd,n,m);
        return root;
}
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
        int index=0;
        map<int,int>m;          //Node to index mapping of inorder
        for(int i=0;i<n;i++)
                m[in[i]]=i;
        return solve(in,pre, index,0,n-1,n,m);
    }



    TreeNode* dfs(vector<int>&postorder, vector<int>&inorder,int preStart, int preEnd, int inStart,int inEnd,map<int,int>&m){
        if(preStart>preEnd || inStart>inEnd)return NULL;
        int inRoot=postorder[preEnd];
        TreeNode* root=new TreeNode(inRoot);//
       int pos=m[inRoot];
        int numsLeft=pos-inStart;
        root->left=dfs(postorder,inorder,preStart,preStart+numsLeft-1,inStart,pos-1,m);//
        root->right=dfs(postorder,inorder,preStart+numsLeft,preEnd-1,pos+1,inEnd,m);//
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return dfs(postorder,inorder,0,postorder.size()-1,0,inorder.size()-1,m);
    }
