class MinStack {
public:
    stack<int> st1;
    stack<int> st2;
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
