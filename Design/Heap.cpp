// Two ways to implement heap with heapify algorithm & without heapify algorithm
// In without heapify, there is no actual binary tree, we assume that the array is a binary tree
1st Without heapify : the below code is for max heap  
class heap{
    public :
    int arr[100];
    int size = 0;
    
    void Insert(int val){   //log(n)
        size++;
        int i = size;
        arr[i]=val;
        while(i>1){
            int parent=i/2;
            if(arr[parent]<arr[i]){
                swap(arr[parent],arr[i]);
                i=parent;
            }
            else{
                return;
            }
        }
    }
    void Delete(){  //so that c++ delete doesnt conflict  //log(n)
        if(!size){
            return;
        }
        arr[1]=arr[size]; //put last element into 1st node so that original 1st element vanished
        int i=1;
        while(i<size){    //take 1st node to its correct position
            int left=2*i;
            int right=2*i+1;
            
            if(left<size && arr[i]<arr[left]){
                swap(arr[i],arr[left]);
                i=left;
            }
            else if(right<size && arr[i]<arr[right]){
                swap(arr[i],arr[right]);
                i=right;
            }
            else{
                return;
            }
        }
    }

    int Top(){
        return arr[1];
    }
};
//h.insert // by default .dot
//After each insertion of deleteion run heapfiy for that node it takes  o(logn) time

// WITH HEAPIFY :-
void maxheapify (vector<int>&arr, int n, int i){  // o(logn)
    int largest =i;  
    int left=2*i;                          //For minheap 2*i+1;
    int right=2*i +1;                      //For minheap 2*i+2;
    if(left<n && arr[largest]<arr[left]){  //For minheap >
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){//For minheap > // we cant do else if because we have to check for both left and right
        largest=right;
    }
    
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

int main(){
    vector<int>arr={-1,34,56,45,43,2};
    int n=arr.size();
    for(int i=n/2;i>0;i--){            //For minheap i=n/2 -1;i>=0;   o(n)
        heapify(arr,n,i);
    }
    // pop out the top element and heapify the remaining array
    swap(arr[1],arr[n-1]);
    n--;
    maxheapify(arr,n,1);
    // insert 1 element and heapify the array
    arr.push_back(100);
    n++;
    maxheapify(arr,n,1);
}
