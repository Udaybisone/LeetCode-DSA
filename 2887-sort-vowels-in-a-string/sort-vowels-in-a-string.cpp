class Solution {
public:
    string sortVowels(string s) {
        string t = "";
        for(auto c:s){
            char ch = tolower(c);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                t += c;
            }
        }
        sort(t.rbegin(),t.rend());
        
        for(auto &c:s){
            char ch = tolower(c);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                c = t.back();
                t.pop_back();
            }
        }
        return s;
    }
};