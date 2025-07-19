class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
       
        int n = bank.size(), prevCnt = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int curCnt = 0;
            for (char c : bank[i]) {
                if (c == '1') curCnt++;
            }
            ans += curCnt * prevCnt;
            prevCnt = (curCnt == 0) ? prevCnt : curCnt;
        }
        return ans;
    }
};

    