//Using array to understand the solution
class MyHashMap {
public:
    int data[1000001];
    MyHashMap() {
        fill(data, data + 1000000, -1);
    }
    void put(int key, int val) {
        data[key] = val;
    }
    int get(int key) {
        return data[key];
    }
    void remove(int key) {
        data[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */



// Without using array 
// define a Node struct to hold key-value pairs and a pointer to the next node
struct Node {
public:
    int key, val;
    Node* next;
    Node(int k, int v, Node* n) {
        key = k;
        val = v;
        next = n;
    }
};

// define a MyHashMap class with a constant size and multiplier
// this implementation uses an array of linked lists to implement a hash table. Each index in the array holds a pointer to the head of a linked list. 
// Each node in the linked list holds a key-value pair and a pointer to the next node in the list. 
// This is a common approach for handling collisions in hash tables, where multiple keys may hash to the same index in the array. 
// The linked list allows us to store multiple key-value pairs at the same index in the array.

class MyHashMap {
public:
    const static int size = 19997;
    const static int mult = 12582917;   // prime no are used to reduce collisions i,e same index for different keys i,e having same linked list node for diff keys.
                                        // Since prime numbers only 2 factor 1 and itself so less collision

    // initialize the data array to hold pointers to Node objects
    Node* data[size] = {};

    // hash function to convert the key to an index in the data array
    int hash(int key) {
        return (int)((long)key * mult % size);
    }

    // put method to add or update a key-value pair
    void put(int key, int val) {
        // remove any existing key-value pair with the same key
        remove(key);
        // get the index for the key
        int h = hash(key);
        // create a new Node object with the key-value pair and add it to the start of the linked list at the index
        Node* node = new Node(key, val, data[h]);
        data[h] = node;  // head yakes 1 steps ahead
    }    

    // get method to retrieve the value associated with a key
    int get(int key) {
        // get the index for the key
        int h = hash(key);
        // iterate over the linked list at the index and return the value associated with the key, if found
        Node* node = data[h];
        for (; node != NULL; node = node->next)
            if (node->key == key) return node->val;
        // return -1 if the key is not found
        return -1;
    }    

    // remove method to delete a key-value pair
    void remove(int key) {
        // get the index for the key
        int h = hash(key);
        // get the first node in the linked list at the index
        Node* node = data[h];
        // return if the linked list is empty
        if (node == NULL) return;
        // delete the first node if it has the key to be removed
        if (node->key == key) {
            data[h] = node->next;
            delete node;
        } else {
            // iterate over the linked list and delete the node with the key to be removed, if found
            for (; node->next != NULL; node = node->next)
                if (node->next->key == key) {
                    Node* temp = node->next;
                    node->next = temp->next;
                    delete temp;
                    return;
                }
        }
    }
};

//TIME COMPLEXITY :-
// hash function: O(1) time complexity, as it simply performs some arithmetic operations on the input key to compute an index in the array.

// put method: O(1) time complexity on average case, but could be O(n) in the worst case. In the average case, the key-value pair is added to the linked list at the computed index, which takes constant time. 
//     In the worst case, however, there could be n elements in the linked list at the computed index, where n is the number of key-value pairs in the hashmap. 
//     In this case, the remove method would be called first, which has a time complexity of O(n) in the worst case due to the need to iterate over the linked list to find the node with the key. 
//     Then, a new node would need to be created and added to the start of the linked list, which also takes O(n) time in the worst case since all the nodes in the linked list need to be shifted down by one to make room for the new node.

// get method: O(1) time complexity on average case, but could be O(n) in the worst case. In the average case, the value associated with the input key is found in constant time since the linked list at the computed index is expected to be small.
//     In the worst case, however, there could be n elements in the linked list at the computed index, where n is the number of key-value pairs in the hashmap. 
//         In this case, the for loop needs to iterate over all n nodes in the linked list to find the node with the input key, which takes O(n) time.

// remove method: O(1) time complexity on average case, but could be O(n) in the worst case. In the average case, the node with the input key is found and removed from the linked list at the computed index in constant time.
//     In the worst case, however, there could be n elements in the linked list at the computed index, where n is the number of key-value pairs in the hashmap. 
//     In this case, the for loop needs to iterate over all n nodes in the linked list to find the node with the input key, which takes O(n) time. 
    Once the node is found, it takes constant time to delete it from the linked list.
