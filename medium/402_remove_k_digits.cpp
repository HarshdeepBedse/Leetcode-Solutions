class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st; 
        string ans;

        for (auto digit : num) {
            while (!st.empty() && st.top() > digit && k > 0) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        
        while (ans.size() > 0 && ans.back() == '0') {
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());

        return ans.empty() ? "0" : ans;
    }
};