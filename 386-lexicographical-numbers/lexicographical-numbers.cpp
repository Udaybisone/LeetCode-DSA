class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int temp = 0;
        int num = 1;
        vector<int>ans;
        ans.push_back(num);

        while(true){
            if(num*10 + temp <=n){
                num = num*10 + temp;
                temp = 0;
                ans.push_back(num);
            }else{
                while(num%10==9){
                    num /= 10;
                }
                if(num==0) break;
                temp = num%10;
                temp++;
                num /= 10;
            }
        }
        return ans;
    }
};