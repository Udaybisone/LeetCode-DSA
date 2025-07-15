class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;

        bool ow = false, oc = false;

        for(auto &ch:word){
            if(ch>='A' && ch<='Z') ch += 32;
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') ow  = true;
            else if(ch>='a' && ch<='z') oc = true;
            else if(ch>='0' && ch<='9') continue;
            else return false;
        }
        return ow && oc;
    }
};