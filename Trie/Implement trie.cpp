class TrieNode{   // must be declared outside the class Trie in leetcode
    public:
    char data;
    TrieNode* child[26];
    bool isTerminal;

    TrieNode(char ch){   // CONSTRUCTOR of TrieNode
        data = ch;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    public:
    TrieNode* root;
    
    Trie(){  // CONSTRUCTOR of Trie 
        root = new TrieNode('\0'); // Constructor : assinging root to NULL i,e '\0'
    }

    void insertdfs(TrieNode* root, string s){
        if(s.size()==0){
            root->isTerminal = true;
            return;
        }
        // assumption, words will be in CAPITAL LETTERS
        int index = s[0]-'A';
        TrieNode* child;

        if(root->child[index]){   //if 1st char is present
            child = root->child[index];
        }
        else{
            child = new TrieNode(s[0]);
            root->child[index] = child;
        }
        // Recursive call
        insertdfs(child, s.substr(1));
    }

    void insert(string word){
        insertdfs(root, word);
    }

    bool searchdfs(TrieNode* root, string s){
        if(s.size()==0){
            return root->isTerminal; 
        }
        int index = s[0]-'A';
        TrieNode* child;
        if(root->child[index]){
            child = root->child[index];
        }
        else{
            return false;
        }
        return searchdfs(child, s.substr(1));
    }

    bool search(string s){
        return searchdfs(root, s);
    }

    //remove a word from trie
    void removedfs(TrieNode* root, string s){
        if(s.size()==0){
            root->isTerminal = false;
            return;
        }
        int index = s[0]-'A';
        TrieNode* child;
        if(root->child[index]){
            child = root->child[index];
        }
        else{
            return;
        }
        removedfs(child, s.substr(1));
        // remove child node if it is useless
        if(child->isTerminal==false){
            // loop to check if child has any child node or not if not then delete it why ? because it is useless why ?because it is not a terminal node and it has no child node
            for(int i=0;i<26;i++){
                if(child->child[i]!=NULL){
                    return;
                }
            }
            delete child;
            root->child[index] = NULL;
        }
    }
    //remove function
    void remove(string s){
        removedfs(root, s);
    }
};


int main(){
    Trie *t;           // creating a trie object using pointer
    t = new Trie();    // dynamically allocating memory to the trie object on heap i,e manually needs to deleted when no longer needed where t points to memory location of trie object

    t->insert("HELLO");  // inserting a word in the trie
    t->insert("HELL");
    //searching a word in the trie
    if(t->search("HELLO")){
        cout<<"found"<<endl;
    }
    // delete
    t->remove("HELLO");

    // Trie t;        // creating a trie object on stack without using a pointer . No need to delete it manually
    // t.insert("HELLO");
    return 0;
}

// time complexity of insert and search is O(L) where L is the length of the word
// time complexity of remove is O(L*N) where L is the length of the word and N is the number of words because we are calling remove function for each word why ? because we have to check if the child node is useless or not
// space complexity is O(N*L) where N is the number of words and L is the length of the word
