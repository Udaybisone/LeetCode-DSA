class Solution {
    int n;
    vector<vector<int>> memo;
    vector<string> words;
    vector<int> groups;

    bool isValid(int i, int j) {
        if (words[i].size() != words[j].size() || groups[i] == groups[j]) return false;
        int diff = 0;
        for (int k = 0; k < words[i].size(); ++k) {
            if (words[i][k] != words[j][k]) diff++;
            if (diff > 1) return false;
        }
        return diff == 1;
    }

    // Returns the longest subsequence starting at index 'i'
    vector<int> dp(int i) {
        if (memo[i][0] != -1) return {memo[i].begin(), memo[i].end()};

        vector<int> best = {i}; // start with only current word

        for (int j = i + 1; j < n; ++j) {
            if (isValid(i, j)) {
                vector<int> candidate = dp(j);
                if (candidate.size() + 1 > best.size()) {
                    best = {i};
                    best.insert(best.end(), candidate.begin(), candidate.end());
                }
            }
        }

        memo[i] = best;
        return best;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& _words, vector<int>& _groups) {
        words = _words;
        groups = _groups;
        n = words.size();

        memo = vector<vector<int>>(n, vector<int>(1, -1));  // memo[i] stores the best subsequence indices starting from i

        vector<int> bestPath;
        for (int i = 0; i < n; ++i) {
            vector<int> path = dp(i);
            if (path.size() > bestPath.size()) bestPath = path;
        }

        vector<string> res;
        for (int idx : bestPath) res.push_back(words[idx]);
        return res;
    }
};
