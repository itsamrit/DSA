implementation of queue with // Time Complexity:  pop function: O(1)   push function: O(1) top function: O(1) size function: O(1)
//👍 whenever queue is empty start and end should be -1
class Queue {
  int * arr;  //since i dont know the size of array so i have to use dynamic array for that i have to use int *arr
  int start, end, currSize, maxSize;  // all the variables inside constructor should be defined 
  public:
    Queue() {                  //constructor called when object is created without size provided by user
      arr = new int[1000];
      start = -1;
      end = -1;
      currSize = 0;
    }

  Queue(int maxSize) {         //constructor called when object is created with size provided by user
    this->maxSize = maxSize;   // or  maxSize = maxSize;  or  (*this). == this->
    arr = new int[maxSize];
    start = -1;
    end = -1;
    currSize = 0;
  }
  void push(int newElement) {
    if (currSize == maxSize) {
      cout << "Queue is full\nExiting..." << endl;
      exit(1);
    }
    if (end == -1) { // if it's empty 
      start = 0;
      end = 0;
    } else
      end = (end + 1) % maxSize;
    arr[end] = newElement;
    cout << "The element pushed is " << newElement << endl;
    currSize++;
  }
  int pop() {        //nothing is poped just the start is changed
    if (start == -1) {
      cout << "Queue Empty\nExiting..." << endl;
    }
    int popped = arr[start];
    if (currSize == 1) {
      start = -1;
      end = -1;
    } else
      start = (start + 1) % maxSize;
    currSize--;
    return popped;
  }
  int top() {
    if (start == -1) {
      cout << "Queue is Empty" << endl;
      exit(1);
    }
    return arr[start];
  }
  int size() {
    return currSize;
  }
};

// time complexity of pop function is O(1), push function is O(1), peek function is O(1) and empty function is O(1)
// implement queue using 2 stacks benefits no limitation of size of queue

class Queue{
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int x){
        s1.push(x);
    }

    void pop(){
        if(!s1.size() && !s2.size()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        if(s2.empty()){   
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    int top(){
        if(!s1.size() && !s2.size()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        if(s2.empty()){            //this case will be very few times so time complexity will be o(1) amortized
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    int size(){
        return s1.size()+s2.size();
    }
};
//best explanation : https://www.youtube.com/watch?v=3Et9MrMc02A&ab_channel=takeUforward

// time complexity of pop is o(n) or amortized o(1), push is O(1) and empty is O(1)
// but why we are using 2 stack instead of array or vector because limitation of size of queue  
