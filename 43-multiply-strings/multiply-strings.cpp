class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        string sum = "";
        int cnt = 0;
        for(int i = m - 1; i >= 0; i--) {
            string pr = "", carry = "0";
            for(int j = n - 1; j >= 0; j--) {
                int k = (num1[j] - '0') * (num2[i] - '0') + stoi(carry);
                string s = to_string(k);
                if(s.size() == 1) {
                    pr = s + pr;
                    carry = "0";
                } else {
                    pr = s.back() + pr;
                    carry = s.substr(0, s.size() - 1);
                }
            }
            if(carry != "0") pr = carry + pr;
            string temp(cnt, '0');
            pr += temp;
            cnt++;

            if(sum == "") {
                sum = pr;
            } else {
                string newsum = "";
                carry = "0";
                int n1 = pr.size() - 1;
                int n2 = sum.size() - 1;

                while(n1 >= 0 || n2 >= 0 || carry != "0") {
                    int digit1 = (n1 >= 0) ? pr[n1] - '0' : 0;
                    int digit2 = (n2 >= 0) ? sum[n2] - '0' : 0;
                    int k = digit1 + digit2 + stoi(carry);
                    string s = to_string(k);
                    if(s.size() == 1) {
                        newsum = s + newsum;
                        carry = "0";
                    } else {
                        newsum = s.back() + newsum;
                        carry = s.substr(0, s.size() - 1);
                    }
                    n1--;
                    n2--;
                }

                sum = newsum;
            }
        }

        // Remove leading zeros
        int i = 0;
        while(i < sum.size() - 1 && sum[i] == '0') i++;
        return sum.substr(i);
    }
};
