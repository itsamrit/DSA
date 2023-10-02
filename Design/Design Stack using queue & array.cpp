//Time Complexity : o(n) for both cases
// https://takeuforward.org/data-structure/implement-stack-using-array/
// 🟩🟩Stack is same as array, so we its implementation is simple
class Stack {
  int size;
  int * arr;
  int top;
  public:
    Stack() {
      top = -1;
      size = 1000;
      arr = new int[size];
    }
  void push(int x) {
    top++;
    arr[top] = x;
  }
  int pop() {
    int x = arr[top];
    top--;
    return x;
  }
  int Top() {
    return arr[top];
  }
  int Size() {
    return top + 1;
  }
};

int main() {

  Stack s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout<<s.Size();
}


//USING QUEUE
//https://takeuforward.org/data-structure/implement-stack-using-single-queue/
class Stack {
  queue <int> q;
  public:
  void Push(int x) {       
    int s = q.size();
    q.push(x);
    for (int i = 0; i < s; i++) {     
      q.push(q.front());
      q.pop();
    }
  }
  void Pop() {
    q.pop();
  }
  int Top() {
    return q.front();
  }
  int Size() {
    return q.size();
  }
};
