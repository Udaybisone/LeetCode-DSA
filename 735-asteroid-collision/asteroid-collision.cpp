class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>st;

        for(auto &it:ast){
            if(it>0) st.push(it);
            else{
                while(!st.empty() && st.top()>0 && abs(it) > abs(st.top())) {
                    st.pop();
                }
                if(!st.empty() && st.top()>0 && abs(it)==st.top()) st.pop();
                else if(st.empty() or st.top()<0) st.push(it);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};