class Solution {
public:
    int maxArea(vector<int>& ht) {
        int n = ht.size();
        int i = 0 , j = n-1;
        int ans = (min(ht[i],ht[j]))*(j-i);
        while(i<j){
            ans = max(ans,min(ht[i],ht[j])*(j-i));
            if(ht[i]<ht[j]) i++;
            else if(ht[i]>ht[j]) j--;
            else i++,j--;
        }
        return ans;
    }
};