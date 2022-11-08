//Tc=o(n*logn=> n*logk)  n for loop and logk for sorting caz there are only k elements in heap
✅✅ 👉 Maxheap(priority_queue<int>pq) pops maximum element & similarly minheap pops out mininum. Minheap : priority_queue<int,vector<int>,greater<int>>pq; 

vector<int> sort(vector<int>arr,int k){
    vector<int>ans;
    priority_queue<int, vector<int>,greater<int>> minheap;         //priority_queue<int> maxheap for sorting in descending order or for kth smallest
    for(int i=0;i<arr.size();i++){
        minheap.push(arr[i]);
        if(minheap.size()>k){ans.push_back(minheap.top());  minheap.pop(); }  //Removing this line will completely sort arr in nlogn //In k sorted array we know that when heap size exceeds k size the smallest must be at top
    }
    //Here minheap.top() gives kth greatest element
    while(minheap.size()){
        ans.push_back(minheap.top());  minheap.pop();
    }
    return ans;
}


Greedy : Further building you can reach with k ladders(u can reach any height) and m bricks.1st push for(i=0 to k) push all elements in pq and assume all climed by ladder then insert for(i=k to n) remove all min element so that they are climed by bricks are limited. If bricks are over this is the building where we can reach.
Print k closest numbers to given number: priority_queue<pair<int,int>>  and  maxheap.push({abs(arr[i]-x),arr[i]});
Top k most frequent element Frequency sort: map[i]++;  minheap.push({i->second,i->first});
Print k closest points from origin:  priority_queue<pair<int, pair<int,int>>maxheap;    maxheap.push({arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1] , {arr[i][0],arr[i][1]}};   //dis of point (x,y) from (0,0)=root(x^2 +y^2)
