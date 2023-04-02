//Prerequisite : inorder = left,root,right ,        pre= root,left,right          post = left,right,root
//tc=o(n)
WRONG POSTORdER   RRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
Node* dfs(vector<int>&in, vector<int>&pre, int & i,int inorderStart,int inorderEnd, int n,map<int,int>&m){
        if(i>=n || inorderStart>inorderEnd) return NULL;  //In postorder : i<0
        int val=pre[i++];          //INpost :i--
        Node* root=new Node(val);
        int position=m[val];
        
        root->left=dfs(in, pre, i, inorderStart,position-1,n,m);  //In postorder: root->right=dfs(..)
        root->right=dfs(in,pre, i, position+1,inorderEnd,n,m);    //In postorder: root->left=dfs(..)
        return root;
}

TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();   
             
        map<int,int>m;          //Node to index mapping of inorder
        for(int i=0;i<n;i++)
                m[in[i]]=i;
        return dfs(in,pre, 0,0,n-1,n,m);  //Since pre 1st root is 0th index & in postoder solve(in,post,n-1,rest same..) as index start from last in post
}
