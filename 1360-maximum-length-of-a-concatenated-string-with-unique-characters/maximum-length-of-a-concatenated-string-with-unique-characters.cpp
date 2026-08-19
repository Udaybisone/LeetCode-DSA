class Solution {
    int ans = 0;
    void f(int i,int mask,vector<string>&arr){
        if(i<0){
            ans = max(ans,__builtin_popcount(mask));
            return;
        }

        f(i-1,mask,arr);

        bool canTake = true;
        for(auto c:arr[i]){
            int b = c-'a';
            if((mask & (1<<b)) != 0) canTake = false;
            mask += (1<<b);
        }
        if(canTake) f(i-1,mask,arr);
    }
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        f(n-1,0,arr);
        return ans;
    }
};