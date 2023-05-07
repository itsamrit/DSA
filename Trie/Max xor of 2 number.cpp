class Node{
	public:
	Node* links[2];  // 🟩 We dont need isComplete. Since we are traversing the whole 32 bits
    // Node(){
    //     memset(links,0,sizeof(links));
    // }
};
class Trie{

	public:
	Node* root;
	Trie(){
		root=new Node();
	}
	void insert(int num){
		Node* node=root;
		for(int i=31; i>=0; i--){
			int bit=(num>>i)&1;   //Right Shift : Remove i bits from last &1 is used to determine the bit value
			if(!node->links[bit]){
				node->links[bit]=new Node();
			}
			node=node->links[bit];
		}
	}
	int maxnum(int num){
		Node* node=root;
		int maxi=0;
		for(int i=31; i>=0; i--){
			int bit=(num>>i)&1;
			if(!node->links[1-bit]){
				node=node->links[bit];  //go forward with whatever bit is present
			}
			else{
				maxi=maxi|(1<<i);
				node=node->links[1-bit];
			}
		}
		return maxi;
	}
};

class Solution {

	public:
	int findMaximumXOR(vector<int>& nums) {
		int ans=0;
		Trie trie;
		for(int i=0; i<nums.size(); i++){
			trie.insert(nums[i]);
		}
		for(int i=0; i<nums.size(); i++){
			ans=max(ans, trie.maxnum(nums[i]));
		}
		return ans;
	}
};
