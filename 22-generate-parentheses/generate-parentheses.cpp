class Solution {
public:
    vector<string> result;
    int N;

    bool isValid(string &str) {
        int total_count = 0;
        for (char &ch : str) {
            if (ch == '(') {
                total_count++;
            } else {
                total_count--;
            }
            if (total_count < 0) return false;
        }
        return total_count == 0;
    }

    void solve(string &current, int n) {
        if (current.length() == 2 * n) {
            if (isValid(current)) {
                result.push_back(current);
            }
            return;
        }

        current.push_back('(');   // ✅ char literal
        solve(current, n);
        current.pop_back();

        current.push_back(')');   // ✅ char literal
        solve(current, n);
        current.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        N = n;
        string current = "";
        solve(current, n);
        return result;
    }
};
