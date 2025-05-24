class Solution {
    // recursive helper:
    // - cur: the current password string being built
    // - seen: set of all length-n substrings we've already covered
    // - total: k^n, how many distinct substrings we need
    // - n,k: parameters from the outer call
    string dfs(string &cur,
               unordered_set<string> &seen,
               int total,
               int n,
               int k) {
        // take the last n chars
        string tail = cur.substr(cur.size() - n, n);
        // if we've already covered this one, backtrack
        if (seen.count(tail)) 
            return "";
        // otherwise mark it covered
        seen.insert(tail);

        // if we've seen them all, we're done
        if ((int)seen.size() == total)
            return cur;

        // try extending by each digit 0..k-1
        for (int c = 0; c < k; ++c) {
            cur.push_back(char('0' + c));
            string ans = dfs(cur, seen, total, n, k);
            if (!ans.empty()) 
                return ans;        // propagate solution up
            cur.pop_back();
        }

        // undo the “seen” mark on backtrack
        seen.erase(tail);
        return "";
    }

public:
    string crackSafe(int n, int k) {
        // compute k^n
        int total = 1;
        for (int i = 0; i < n; ++i) total *= k;

        // empty set of seen substrings
        unordered_set<string> seen;
        seen.reserve(total);

        // start with "000...0" of length n
        string cur(n, '0');

        // recurse
        return dfs(cur, seen, total, n, k);
    }
};
