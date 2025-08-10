class Solution {
public:
    bool reorderedPowerOf2(int n) {
        map<char,long long>mp;
        string s = to_string(n);
        sort(s.begin(),s.end());

        long long k = 1;
        while(k<=1e9){
            string temp = to_string(k);
            sort(temp.begin(),temp.end());
            cout<<temp<<endl;
            if(s==temp) return true;
            k *= 2;
        }
        return false;
    }
};