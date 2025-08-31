class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int i = 0;
        int ans = 0;
        cout<<n<<endl;
        while(i<n/2){
            int j = n-1-i;
            while(j>i && s[j] != s[i]) j--;

            if (j == i) {
                swap(s[j], s[j+1]);
                ans++;
                continue;
            }
            
            while(j<n-1-i) {
                swap(s[j],s[j+1]);
                ans++;
                j++;
            }
            i++;
        }
        return ans;
    }
};