class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        int n = h.size();

        stack<int>st;
        vector<int>ans(n);

        for(int i=n-1; i>=0; i--){
            int cnt = 0;

            while(!st.empty() && st.top()<h[i]){
                cnt++;
                st.pop();
            }

            ans[i] = cnt + (!(st.empty()));
            st.push(h[i]);
        }
        return ans;
    }
};