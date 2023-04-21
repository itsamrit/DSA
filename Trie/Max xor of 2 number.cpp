class TrieNode{
public:
    TrieNode* left;
    TrieNode* right;
};

void insert(int n, TrieNode* head){
    TrieNode* curr = head;
    for(int i=31; i>=0; i--){
        int b = (n>>i)&1;
        if(b==0){
            if(!curr->left){
                curr->left = new TrieNode();
            }
            curr = curr->left;
        }
        else{
            if(!curr->right){
                curr->right = new TrieNode();
            }
            curr = curr->right;
        }
    }
}

int findMaxXorPair(TrieNode* head, int* arr, int n){
    int max_xor = INT_MIN;
    for(int i=0; i<n; i++){
        int value = arr[i];
        TrieNode* curr = head;
        int curr_xor = 0;
        for(int j=31; j>=0; j--){
            int b = (value>>j)&1;
            if(b==0){
                if(curr->right){
                    curr_xor += pow(2, j);
                    curr = curr->right;
                }
                else{
                    curr = curr->left;
                }
            }
            else{
                if(curr->left){
                    curr_xor += pow(2, j);
                    curr = curr->left;
                }
                else{
                    curr = curr->right;
                }
            }
        }
        if(curr_xor>max_xor){
            max_xor = curr_xor;
        }
    }
    return max_xor;
}

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int* arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = nums[i];
        }
        TrieNode* head = new TrieNode();
        for(int i=0; i<n; i++){
            insert(arr[i], head);
        }
        return findMaxXorPair(head, arr, n);
    }
};

// time complexity is O(N*log(max(arr[i]))) where N is the number of elements in the array and max(arr[i]) is the maximum element in the array why log ? because we are iterating over the bits of the number so log(arr[i]) tells us the number of bits in the number

// define the flow of the code
// first we are creating a trie and inserting all the number in the trie then we are finding the max xor of each number with all the number in trie 
//    then we are taking the max of all the max xor of each number with all the number in trie & since we are going either left or right in the trie so we are iterating over the bits of the number and max bits is 32 so time complexity is O(32*N) where N is the number of elements in the array
// yes it is like a binary trie 
