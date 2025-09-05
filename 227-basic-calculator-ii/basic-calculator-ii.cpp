class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int num = 0;
        char op = '+';
        s += '+';

        for (char ch : s) {
            if (ch == ' ') continue;
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else {
                if (op == '+') {
                    stk.push(num);
                } else if (op == '-') {
                    stk.push(-num);
                } else if (op == '*') {
                    int top = stk.top(); stk.pop();
                    stk.push(top * num);
                } else if (op == '/') {
                    int top = stk.top(); stk.pop();
                    stk.push(top / num);
                }
                op = ch;
                num = 0;
            }
        }

        int result = 0;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};
