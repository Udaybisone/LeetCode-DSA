class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        
        queue<string>q;
        unordered_set<string>st;
        int n = s.size();
        q.push(s);
        st.insert(s);
        string ans = s;

        while(!q.empty()){
            auto str = q.front();
            q.pop();

            ans = min(ans,str);
            
            string temp = str;
            for(int i=1; i<n; i+=2){
                int c = ((str[i]-'0') + a)%10;
                temp[i] = '0' + c;
            }
            if(!st.count(temp)) {
                q.push(temp);
                st.insert(temp);
            }
            temp = str;
            int tb = b;
            while(tb--){
                temp = temp.back() + temp;
                temp.pop_back();
            }
            if(!st.count(temp)){
                q.push(temp);
                st.insert(temp);
            }
        }
        return ans;
    }
};