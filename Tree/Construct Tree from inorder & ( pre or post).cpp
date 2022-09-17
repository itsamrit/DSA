Node* solve(vector<int>&in, vector<int>&pre, int & index,int inorderStart,int inorderEnd, int n,map<int,int>&m){
        if(index>=n || inorderStart>inorderEnd) return NULL;  //In post : index<0
        int element=pre[index++];          //INpost :index--
        Node* root=new Node(element);
        int position=m[element];
        
        root->left=solve(in, pre, index, inorderStart,position-1,n,m);  //INpost: postion+1,inorderEnd,n
        root->right= solve(in,pre, index, position+1,inorderEnd,n,m);   //Inpost: inorderStart,post-1,n
        return root;
}

TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();   
             
        map<int,int>m;          //Node to index mapping of inorder
        for(int i=0;i<n;i++)
                m[in[i]]=i;
        return solve(in,pre, 0,0,n-1,n,m);  //in post pre,n-1 as index start from last in post
}
