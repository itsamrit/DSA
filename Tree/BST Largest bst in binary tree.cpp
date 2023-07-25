You can solve it by making NodeValue datasturcture as normal vector<int> . See codelibrary by yogesh video. 
// tc:o(n) sco(n) 

class NodeValue {
public:
    int maxNode, minNode, maxSize;  
    NodeValue(int minn, int maxx, int maxSizee) {
        maxNode = maxx;
        minNode = minn;
        maxSize = maxSizee;
    }
};

class Solution {
    private:                                                                   //👍U can make this public,but private will make impact on interviewer
    NodeValue dfs(TreeNode* root) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        if (left.maxNode < root->val && root->val < right.minNode) {            //🟩 If Current node is greater than max in left AND smaller than min in right and below subtree is already bst i,e it doesn't return intmax and intmin then  it is a BST.
            return NodeValue( min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
        }
        
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));   // Otherwise, return [-inf, inf] so that parent can't be valid BST
    }

    public:
    int largestBSTSubtree(TreeNode* root) {
        return dfs(root).maxSize;
    }
};
