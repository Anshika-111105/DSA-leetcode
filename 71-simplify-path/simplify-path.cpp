class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string part;

        while (getline(ss, part, '/')) {
            if (part == "" || part == ".") continue;
            if (part == "..") {
                if (!st.empty()) st.pop();
            } else {
                st.push(part);
            }
        }

        if (st.empty()) return "/";

        vector<string> dirs;
        while (!st.empty()) {
            dirs.push_back(st.top());
            st.pop();
        }

        reverse(dirs.begin(), dirs.end());
        string res;
        for (auto &d : dirs) {
            res += "/" + d;
        }
        return res;
    }
};