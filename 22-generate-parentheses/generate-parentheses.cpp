class Solution {
public:
    vector<string> result;

    void solve(string &current, int open, int close, int n) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open < n) { // Add '(' if we still can
            current.push_back('(');
            solve(current, open + 1, close, n);
            current.pop_back();
        }

        if (close < open) { // Add ')' if it won’t make it invalid
            current.push_back(')');
            solve(current, open, close + 1, n);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string current;
        solve(current, 0, 0, n);
        return result;
    }
};
