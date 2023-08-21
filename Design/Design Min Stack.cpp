// MinStack Properties: it push,pops & give top like normal stack i,e never pops min element 
//           🟩   Additional functionality of giving min element using another stack which stores monotonically decreasing elements

class MinStack {
public:
    stack<int> st1;  //🟩Like normal stack which push,pop & give top like normal stack
    stack<int> st2;  //🟩Maintaining a Monotonically decreasing stack to have a additional functionality of giving min element of stack
    MinStack() {  // why nothing in constructor? because we are using stl stack so no need to initialize it
    }

    void push(int x) {
        st1.push(x);
        if(st2.empty() || st2.top() >= x) st2.push(x);
    }
    
    void pop() {
        if(st1.top() == st2.top())
            st2.pop();
        st1.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};

// st2 is monotoincally increasing stack and st1 is used to pop elements & we are not popping min element we are popping top element of st1
// explain the above code flow with example of 5, 6, 3, 7, 2, 1, 8. 
// so the code flow will be like this
// push(5) -> st1 = 5, st2 = 5
// push(6) -> st1 = 5, 6, st2 = 5
// push(3) -> st1 = 5, 6, 3, st2 = 5, 3
// push(7) -> st1 = 5, 6, 3, 7, st2 = 5, 3
// push(2) -> st1 = 5, 6, 3, 7, 2, st2 = 5, 3, 2
// push(1) -> st1 = 5, 6, 3, 7, 2, 1, st2 = 5, 3, 2, 1
// push(8) -> st1 = 5, 6, 3, 7, 2, 1, 8, st2 = 5, 3, 2, 1
// pop() -> st1 = 5, 6, 3, 7, 2, 1, st2 = 5, 3, 2, 1
