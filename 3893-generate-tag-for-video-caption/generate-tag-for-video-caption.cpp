class Solution {
public:
    string generateTag(string s) {
        string temp = "";
        string ans = "#";
        for(auto c:s){
            if(c==' '){
                if(temp.size()>0){
                    temp[0] = toupper(temp[0]);
                    ans += temp;
                    if(ans.size()>=100){
                        ans[1] += 32;
                        return ans.substr(0,100);
                    }
                }
                temp = "";
            }else if((c>='a' && c<='z') or (c>='A' && c<='Z')){
                temp += (tolower(c));
            }
        }
        if(temp.size()>0){
            temp[0] = toupper(temp[0]);
            ans += temp;
            if(ans.size()>=100){
                ans[1] += 32;
                return ans.substr(0,100);
            }
        }
        ans[1] += 32;
        return ans;
    }
};