//Prerequisite : inorder = left,root,right ,        pre= root,left,right          post = left,right,root

Node* dfs(vector<int>&in, vector<int>&pre, int & index,int inorderStart,int inorderEnd, int n,map<int,int>&m){
        if(index>=n || inorderStart>inorderEnd) return NULL;  //In postorder : index<0
        int temp=pre[index++];          //INpost :index--
        Node* root=new Node(temp);
        int position=m[temp];
        
        root->left=dfs(in, pre, index, inorderStart,position-1,n,m);  //In postorder: postion+1,inorderEnd,n
        root->right=dfs(in,pre, index, position+1,inorderEnd,n,m);   //In postorder: inorderStart,post-1,n
        return root;
}

TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();   
             
        map<int,int>m;          //Node to index mapping of inorder
        for(int i=0;i<n;i++)
                m[in[i]]=i;
        return dfs(in,pre, 0,0,n-1,n,m);  //in postoder solve(in,post,n-1,rest same..) as index start from last in post
}
