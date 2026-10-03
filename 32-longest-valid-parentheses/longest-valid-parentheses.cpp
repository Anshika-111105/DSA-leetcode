class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> stack(n + 1);
        int top = -1;
        stack[++top] = -1;

        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stack[++top] = i;
            } else {
                top--;

                if (top == -1) {
                    stack[++top] = i;
                } else {
                    maxLen = max(maxLen, i - stack[top]);
                }
            }
        }

        return maxLen;
    }
};