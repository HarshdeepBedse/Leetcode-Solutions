class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int i = 0;
        while (i < path.size()) {
            // Skip leading slashes
            while (i < path.size() && path[i] == '/') {
                ++i;
            }
            int start = i;
            int end = i;
            // Find the end of the current segment
            while (end < path.size() && path[end] != '/') {
                ++end;
            }
            string minpath = path.substr(start, end - start);
            i = end; 

            if (minpath == "." || minpath.empty()) {
                
                continue;
            } else if (minpath == "..") {
                
                if (!s.empty()) {
                    s.pop();
                }
            } else {
                
                s.push(minpath);
            }
        }

        // Build the final path
        string ans;
        while (!s.empty()) {
            ans = "/" + s.top() + ans;
            s.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};