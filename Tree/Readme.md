👉If we need to start a fresh traversing from topmost root for each node our soln is o(n^2) i,e not dp

else o(n) soln.

🟢To make dp soln there is no fixed formula u need to think considering tree of either 0 node , 3 nodes , 5 nodes.

👉In BFS,while using normal queue we can fix the size of each loop if required while(q.size()){ sz=q.size(); for(int i=0 to sz)..}

When using priority_queue we dont fix the size of loop as priority queue changes at each iteration. while(pq.size()) NO sz defined


👉All questions can be solved with int,TreeNode* dfs except printing all paths or nodes but all questions cant be solved without any parameter i,e void.
void and int,TreeNode* dfs have same tc since we are not using extenal dp array like in combination.

👉If data of nodes is not only affected by left or right child but also by parent node or any other node u need to link all nodes with parent nodes to make it like graph to traverse.
If u want data saved in parent node use &data while passing in dfs & u will get data without linking to parent node.

👉Subtree tc o(n*m)

👉There is all left element strictly lesser & right stictly greater than root just like sorted array.

All elements of BST are unique.

👉Never return between loop either at starting or at end (not applicable for dp)
Other wise chaos like binary tree path wrong answers

Both in diameter & lcs u cant store distance or node using & of left & right or not do
lca is also dp cant be solved using void

👉 In tree Bfs we dont write loop for all conneted nodes instead we directlly write algo for left & right

👉 Pass & in tree just like we pass normally void dfs(TreeNode* &root1)
