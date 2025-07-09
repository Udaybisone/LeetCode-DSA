class Solution {
public:
    int maxFreeTime(int evt, int k, vector<int>& st, vector<int>& et) {
        int n = st.size();
        if(et[n-1]!=evt) {
            et.push_back(evt);
            st.push_back(evt);
            n++;
        }
        int sum = 0;
        int last = 0;
        for(int i=0; i<=min(n-1,k); i++){
            sum += (st[i]-last);
            last = et[i];
        }
        int ans = sum;
        
        int i = 1;
        last = 0;
        while(i+k < n){
            int j = i+k;
            sum -= (st[i-1]-last);
            last = et[i-1];
            sum += (st[j]-et[j-1]);
            ans = max(ans,sum);
            i++;
        }
        return ans;
    }
};