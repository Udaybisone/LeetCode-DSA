class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        if(k>=num.size()) return "0";
        for(auto ch:num){
            while(!st.empty() && ch<st.top() && k>0) {
                st.pop();
                k--;
            }

            st.push(ch);
        }
        string ans = "";
        while(!st.empty()){
            if(k>0){
                k--;
                st.pop();
                continue;

            }
            ans += st.top();
            st.pop();
        }
        while(ans.size()>1 && ans.back()=='0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};