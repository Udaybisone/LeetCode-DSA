class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string>res;string temp = "";
        for(int i=0; i<n; i++){
            temp += s[i];
            if(temp.size()==k) {
                res.push_back(temp);
                temp = "";
            }
        }

        if(temp.size()>0){
            string temp2(k-temp.size(),fill);
            temp += temp2;
            res.push_back(temp);
        }
        
        return res;
    }
};