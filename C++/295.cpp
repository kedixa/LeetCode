class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> g;
    priority_queue<int, vector<int>, less<int>> l;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!l.empty() && num > l.top()) g.push(num);
        else l.push(num);
        if(l.size() > g.size() + 1)
            g.push(l.top()), l.pop();
        if(l.size() < g.size())
            l.push(g.top()), g.pop();
    }
    
    double findMedian() {
        if(l.size() == g.size())
            return (l.top() + g.top()) / 2.0;
        else return l.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
