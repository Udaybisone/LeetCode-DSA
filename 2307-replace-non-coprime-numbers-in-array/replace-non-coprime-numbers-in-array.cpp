class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        if(n==1) return nums;
        st.push(nums[0]);
        for(int i=1; i<n; i++){
            st.push(nums[i]);
            while(st.size()>1){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                int gcd = __gcd(num1,num2);
                if(gcd>1){
                    long long lcm = (num1*1LL*num2)/(gcd);
                    st.push(lcm);
                }else{
                    st.push(num2);
                    st.push(num1);
                    break;
                }
            } 
        }

        vector<int>ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};