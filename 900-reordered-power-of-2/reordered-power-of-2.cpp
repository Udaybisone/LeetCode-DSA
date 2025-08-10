class Solution {
public:
    bool reorderedPowerOf2(int n) {
        map<char,long long>mp;
        string s = to_string(n);
        sort(s.rbegin(),s.rend());

        long long k = 1;
        while(k<=stol(s)){
            string temp = to_string(k);
            sort(temp.rbegin(),temp.rend());
            cout<<temp<<endl;
            if(s==temp) return true;
            k *= 2;
        }
        return false;
    }
};