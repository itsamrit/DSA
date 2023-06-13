// LRU put() function removes least recently used if capacity to put new node is full & puts the new node
// get() & put() function makes the node most recently used .both have tc o(1)
// if something already exist remove the previous key,value of it & insert or put new node, no removal of lru needed even if capacity is full since we are removing 1 node

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache {
public:
    class node{ //👍U can make class node outside this class also like in implementation of trie
        public:
            int key;
            int val;
            node* prev;
            node* next;
            node(int k, int v){ 
                key = k;
                val = v;
            }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int capacity;
    unordered_map<int,node*> map;
    
    LRUCache(int capacity) {        //it is called only when new object is created //u can also do (int c){ capacity = c;
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode(node* curNode){
        node* prevNode = curNode->prev;
        node* nextNode = curNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    void addNode(node* curNode){
        curNode->next = head->next;
        curNode->prev = head;
        curNode->next->prev = curNode;
        head->next = curNode;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        node* curNode = map[key];
        int result = curNode->val;
        map.erase(key);
        deleteNode(curNode);
        addNode(curNode);
        map[key] = head->next;
        return result;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            node* curNode = map[key];
            map.erase(key);
            deleteNode(curNode);
        }
        if(map.size() == capacity){
            map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        map[key] = head->next;
    }
};



//LFU CACHE HARD

class LFUCache {
public:
    int Capacity, minFrequency = 0, currentSize = 0;
    unordered_map<int, list<int>>frequencyList;
    unordered_map<int, list<int>::iterator>keyNode;
    unordered_map<int, pair<int, int>>frequency;

    LFUCache(int capacity) {
        Capacity = capacity;
        minFrequency = 0, currentSize = 0;
    }
    
    int get(int key) {
        if(keyNode.find(key) == keyNode.end()) return -1;
        int keyFreq = frequency[key].first;
        frequencyList[keyFreq].erase(keyNode[key]);
        frequency[key].first++;
        frequencyList[frequency[key].first].push_front(key);
        keyNode[key] = frequencyList[frequency[key].first].begin();
        if(frequencyList[minFrequency].size() == 0) minFrequency++;
        return frequency[key].second;
    }
    
    void put(int key, int value) {
        if(Capacity <= 0) return;
        if(keyNode.find(key) != keyNode.end()){
            frequency[key].second = value;
            get(key);
            return;
        }
        // New Element
        if(currentSize == Capacity){
            int minFreqBack = frequencyList[minFrequency].back();
            keyNode.erase(minFreqBack);
            frequency.erase(key);
            frequencyList[minFrequency].pop_back();
            currentSize--;
        }
        currentSize++;
        minFrequency = 1;
        frequencyList[minFrequency].push_front(key);
        keyNode[key] = frequencyList[minFrequency].begin();
        frequency[key].first = 1, frequency[key].second = value;
    }
};


//If asked to implement list also 
struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addfront(Node* node){
        Node* temp=head->next;
        node->next=temp;
        node->prev=head;
        temp->prev=node;
        head->next=node;
        size++;
    }
    void removenode(Node* delnode){
        Node* delprev=delnode->prev;
        Node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        size--;
    }
};
