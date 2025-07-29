class MedianFinder {
    priority_queue<int,vector<int>,greater<>>minpq;
    priority_queue<int>maxpq;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minpq.empty() || minpq.top() > num) maxpq.push(num);
        else minpq.push(num);

        if(maxpq.size() >= minpq.size()+2) {
            minpq.push(maxpq.top());
            maxpq.pop();
        }else if(maxpq.size() < minpq.size()){
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }
    
    double findMedian() {
        double ans;
        if(maxpq.size()>minpq.size()) ans = maxpq.top();
        else ans = ((maxpq.top()+minpq.top())*1.0)/2;
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */