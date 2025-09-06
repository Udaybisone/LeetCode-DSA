class Solution {
    typedef unordered_map<string, int> MAP;
public:
    string countOfAtoms(string s) {
        int n = s.size();

        stack<MAP>st;
        st.push(MAP());
        int i = 0;


        while(i<n){
            if(s[i]=='('){
                st.push(MAP());
                i++;
            }else if(s[i]==')'){
                MAP currMap = st.top();
                st.pop();
                i++;
                string multiplier;
                while(i<n && isdigit(s[i])){
                    multiplier += s[i];
                    i++;
                }
                if(!multiplier.empty()){
                    int mult = stoi(multiplier);
                    for(auto &[atom,cnt]:currMap){
                        currMap[atom] = cnt*mult;
                    }
                }

                for(auto &[atom,cnt]:currMap){
                    st.top()[atom] += cnt;
                }
            }else{
                string currAtom;
                currAtom += s[i];
                i++;
                while(i<n && islower(s[i])){
                    currAtom += s[i];
                    i++;
                }

                string currCount;
                while(i<n && isdigit(s[i])){
                    currCount += s[i];
                    i++;
                }

                int cnt = currCount.empty() ? 1:stoi(currCount);
                st.top()[currAtom] += cnt;
            }
        }

        map<string, int> sortedMap(begin(st.top()), end(st.top()));

        string result;
        for (auto& [atom, count] : sortedMap) {
            result += atom;
            if (count > 1) {
                result += to_string(count);
            }
        }

        return result;
    }
};