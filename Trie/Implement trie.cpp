class TrieNode{
    public:
        bool isComplete;
        TrieNode* child[26];   // IN tree Node* left; the we check if(!left) here we check if(!child[i])
        // TrieNode(){             // 🟩 Since by deault isCompleete is false and all child values are NUll or 0 we dont need constructor
        //     isComplete = false;
        //     memset(child,0,sizeof(child));
        // }
};
class Trie {
public:
    TrieNode* root;    // defining pointer to point at root node. Here only pointer is declared not its position.
    
    Trie() {
        root = new TrieNode();   // here position of above pointer is declared i,e root of whole tree
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(auto it:word){
            int ind = it - 'a';    //🟩Assumption all char are in small letters
            if(!node->child[ind])    
                node->child[ind] = new TrieNode();
            node = node->child[ind];
        }
        node->isComplete = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(auto it:word){
            int ind = it - 'a';
            if(!node->child[ind])
                return false;
            node = node->child[ind];
        }
        return node->isComplete;    // If Checking whether there is word having all the starting words of prefix whether it at prefix or not then : return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
