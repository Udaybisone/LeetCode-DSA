class Solution {
public:
    long long countVowels(string word) {
        long long sum = 0,ans = 0;
        int i = 0;
        for(auto c:word){
            if(c=='u' or c=='a' or c=='e' or c=='i' or c=='o'){
                ans += (sum + i + 1);
                sum = sum + i + 1;
            }else{
                ans += sum;
            }
            i++;
        }

        return ans;
    }
};