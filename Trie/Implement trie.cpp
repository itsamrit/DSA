class TrieNode{
    public:
        bool isComplete;
        TrieNode* children[26];   // IN tree Node* left; the we check if(!left) here we check if(!children[i])
        // TrieNode(){             // 🟩 Since by deault isCompleete is false and all children values are NUll or 0 we dont need constructor
        //     isComplete = false;
        //     memset(children,0,sizeof(children));
        // }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(auto it:word){
            int ind = it - 'a';    //🟩Assumption all char are in small letters
            if(!node->children[ind])    
                node->children[ind] = new TrieNode();
            node = node->children[ind];
        }
        node->isComplete = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(auto it:word){
            int ind = it - 'a';
            if(!node->children[ind])
                return false;
            node = node->children[ind];
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
