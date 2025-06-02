class Solution {
public:
    int candy(vector<int>& v) {
        int n = v.size();
        if (n == 1) return 1;
        int inc = 0, dec = 0, f = 1;  // f = length of last increasing seq, initialized to 1
        int res = 1; // First child always gets 1 candy

        for (int i = 1; i < n; i++) {
            if (v[i] > v[i - 1]) {
                inc++;
                f = inc + 1;
                res += f;
                dec = 0; // reset decreasing
            } else if (v[i] == v[i - 1]) {
                inc = 0;
                dec = 0;
                f = 1;
                res += 1; // each child gets at least 1 candy
            } else { // v[i] < v[i - 1]
                dec++;
                inc = 0;
                res += dec;
                if (dec >= f) res++; // peak needs to be adjusted
            }
        }

        return res;
    }
};
