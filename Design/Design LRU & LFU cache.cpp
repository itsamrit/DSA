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
    unordered_map<int,pair<int,int>> cache; // map[key] = {value,count}
    vector<deque<int>> counter; // one deque per count
    int max_size, num_elements;

    void increment_element(int key) {
        // increment cache counter
        cache[key].second++;
        // increase size of counter if necessary
        while (counter.size() <= cache[key].second)
            counter.push_back(deque<int>());
        // add a new element into the appropriate deque
        counter[cache[key].second].push_back(key);
    }

    void remove_LFU_element() {
        bool success = false;
        // start from the front of the counter
        for (int i = 0; i < counter.size() && !success; i++) {
            // start at the front of each deque
            while (!counter[i].empty() && !success) {
                // if this count is valid, delete the entry in the cache
                if (cache[counter[i].front()].second == i) {
                    success = true;
                    cache.erase(counter[i].front());
                    num_elements--;
                }
                counter[i].pop_front(); // delete invalid and 1st valid
            }
        }
    }

public:
    LFUCache(int c) {
        max_size = c;
        num_elements = 0;
        counter = {{}};
    }

    int get(int key) {
        // if not found, return -1
        if (cache.find(key) == cache.end())
            return -1;
        // count use
        increment_element(key);
        // return the value
        return cache[key].first;
    }
    
    void put(int key, int value) {
        // protect against capacity = 0
        if (max_size == 0) return;
        // if key exists
        if (cache.find(key) != cache.end()) {
            cache[key].first = value;
            increment_element(key);
            return;
        }
        // if at capacity
        if (num_elements == max_size)
            remove_LFU_element();
        // add the new key
        cache[key] = make_pair(value,0);
        counter[0].push_back(key);
        num_elements++;
    }
};
