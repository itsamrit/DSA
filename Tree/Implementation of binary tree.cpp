class node {
    public:
        int data;
        node *left;
        node *right;
        node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

node *buildTree() {
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    node *root = new node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int main(){
    node *root = buildTree();
    return 0;
}

// example input: 1 2 4 -1 -1 5 -1 -1 3 6 // -1 represents NULL