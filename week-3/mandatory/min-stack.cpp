class MinStack {
    stack<int> main;
    stack<int> minstack;
public:
    void push(int value) {
        main.push(value);
        if(minstack.empty() || value<=minstack.top()) {
            minstack.push(value);
        }
    }
    
    void pop() {
        if(main.top() == minstack.top()) {
            minstack.pop();
        }
        main.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */