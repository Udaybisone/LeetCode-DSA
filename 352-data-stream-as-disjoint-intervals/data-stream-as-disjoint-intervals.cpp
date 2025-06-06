class SummaryRanges {
    vector<vector<int>> v;
public:
    SummaryRanges() {}

    void merger(int i) {
        v[i - 1][1] = v[i][1];
        v.erase(v.begin() + i);
    }

    void add(int i, int value) {
        v.insert(v.begin() + i, {value, value});
    }

    void addNum(int value) {
        int n = v.size();
        if (n == 0 || v[n - 1][1] + 1 < value) {
            v.push_back({value, value});
            return;
        }
        if (v[n - 1][1] + 1 == value) {
            v[n - 1][1] = value;
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (value >= v[i][0] && value <= v[i][1]) return;

            if (value < v[i][0]) {
                if (i > 0 && v[i - 1][1] + 1 == value && v[i][0] - 1 == value) {
                    merger(i);
                    return;
                }
                if (v[i][0] - 1 == value) {
                    v[i][0] = value;
                    return;
                }
                if (i > 0 && v[i - 1][1] + 1 == value) {
                    v[i - 1][1] = value;
                    return;
                }
                add(i, value);
                return;
            }
        }
    }

    vector<vector<int>> getIntervals() {
        return v;
    }
};
