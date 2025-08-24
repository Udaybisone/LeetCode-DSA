class StockSpanner {
    int currday;
    stack<pair<int,int>>st;
public:
    StockSpanner() {
        currday = 1;
    }
    
    int next(int price) {
        while(!st.empty() && price >= st.top().first){
            st.pop();
        }
        if(st.empty()){
            st.push({price,currday++});
            return currday-1;
        }
        int ans = currday - st.top().second;
        st.push({price,currday++});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */