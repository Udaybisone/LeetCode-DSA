class Solution {
    int n;
    vector<int> st;

    void build(int i, int j, int idx, vector<int>& b) {
        if (i == j) {
            st[idx] = b[i];
            return;
        }
        int mid = (i + j) / 2;
        build(i, mid, 2*idx+1, b);
        build(mid+1, j, 2*idx+2, b);
        st[idx] = max(st[2*idx+1], st[2*idx+2]);
    }

    void find(int i, int j, int idx, int val) {
        if (i == j) {
            st[idx] = -1;  // mark basket used
            return;
        }
        int mid = (i + j) / 2;
        if (st[2*idx+1] >= val)
            find(i, mid, 2*idx+1, val);
        else
            find(mid+1, j, 2*idx+2, val);
        st[idx] = max(st[2*idx+1], st[2*idx+2]);
    }

public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        n = f.size();
        st.resize(4 * n, -1);
        build(0, n-1, 0, b);

        int cnt = 0;
        for (int val : f) {
            if (st[0] >= val)
                find(0, n-1, 0, val);
            else
                cnt++;
        }
        return cnt;
    }
};
