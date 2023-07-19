// Problems on leetcode based on this algo : Vertical Order Traversal, Vertical order sum,Vertical width of tree by BFS(top,bottom view)
// NOTE : ONLY BFS SOLUTION likE dijkstra
// Iterative:
vector<vector<int>> verticalTraversal(Node* root){
        vector<vector<int>> ans;
        if(!root)return ans;
        map<int, vector<int>> m;             //🟩int(key) indicates col no & vector<int> is all nodes in that col.
        queue<pair<TreeNode*, int>> q;       
        q.push({root, 0});                   // q.push(node,col no); We assume root as col no 0 & all left will become negative col no as ...-3, -2, -1, (root)0, 1,2 3 ...
        while(q.size()){
            int sizee = q.size();
            vector<pair<int, int>>temp; 
            for(int i=0;i<sizee;i++){
                pair<TreeNode*, int> c = q.front();
                q.pop();
                temp.push_back({c.second, c.first->val});
                if(c.first->left) q.push({c.first->left,  c.second - 1});
                if(c.first->right) q.push({c.first->right,c.second + 1});
            }
            sort(temp.begin(),temp.end());                       //if 5,6 are in same col & same row i,e in same cell so 5 comes first
            for(int i=0;i<temp.size();i++){
                m[temp[i].first].push_back(temp[i].second);
            }  
        }
        for(auto it:m)ans.push_back(it.second);             //CANT USE UNORDERED_MAP since we want col no to be sorted
        return ans; 
}
