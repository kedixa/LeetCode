class MyStack {
    queue<int> q[2];
    int idx;
public:
    /** Initialize your data structure here. */
    MyStack() {
        idx = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q[idx].push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(q[idx].size() > 1) {
            q[1-idx].push(q[idx].front());
            q[idx].pop();
        }
        int x = q[idx].front();
        q[idx].pop();
        idx = 1 - idx;
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return q[idx].back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q[0].empty() && q[1].empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
