class Solution {
public:
    struct Node
    {
        Node* link[2];
        Node* get(int bit)
        {
            return link[bit];
        }
        void put(int bit, Node* node)
        {
            link[bit]=node;
        }
        bool check(int bit)
        {
            return (link[bit]!=NULL);
        }
    };
    class Trie
    {
        public:
        Node* root;
        Trie()
        {
            root=new Node();
        }
        public:
        void insert(int num)
        {
            Node* node=root;
            for(int i=31;i>=0;i--)
            {
                int bit=(num>>i)&1;
                if(!node->check(bit))
                {
                    node->put(bit,new Node());
                }
                node=node->get(bit);
            }
        }
        int getMax(int num)
        {
            Node* node=root;
            int ans=0;
            for(int i=31;i>=0;i--)
            {
                int bit=(num>>i)&1;
                if(node->check(1-bit))
                {
                    ans=ans|(1<<i);
                    node=node->get(1-bit);
                }
                else
                {
                    node=node->get(bit);
                }
            }
            return ans;
        }
    };
    int findMaximumXOR(vector<int>& A) {
        int n=A.size();
        Trie trie;
        for(auto &it:A) trie.insert(it);
        int ans=0;
        for(auto &it:A)
        {
            ans=max(ans,trie.getMax(it));
        }
        return ans;
    }
};
