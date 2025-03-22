class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int result = 0;
        int sign = 1; // Current sign (+1 or -1)
        stack<int> stk; // To store previous results and signs
        
        int i = 0;
        while (i < n) {
            char ch = s[i];

            if (isdigit(ch)) {
                int num = 0;
                // Parse full number (can have multiple digits)
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                result += sign * num;
                continue; // Already moved `i` inside while
            }

            else if (ch == '+') {
                sign = 1;
            }

            else if (ch == '-') {
                sign = -1;
            }

            else if (ch == '(') {
                // Save the current state
                stk.push(result);
                stk.push(sign);
                // Reset for new sub-expression
                result = 0;
                sign = 1;
            }

            else if (ch == ')') {
                // End of sub-expression, combine it
                int prevSign = stk.top(); stk.pop();
                int prevResult = stk.top(); stk.pop();
                result = prevResult + prevSign * result;
            }

            // Ignore spaces
            i++;
        }

        return result;
    }
};