class Solution {
public:
    int compress(vector<char>& s) {
 
        int index = 0;
        int count = 0;
        char prev = s[0];
        
        for (int i = 0; i < s.size(); i++) {
            if (prev == s[i]) {
                count++;
            } else {
                s[index++] = prev;
                
                if (count > 1) {
                    int start = index;
                    while (count > 0) {
                        s[index++] = (count % 10) + '0';
                        count /= 10;
                    }
                    std::reverse(s.begin() + start, s.begin() + index);
                }
                prev = s[i];
                count = 1;
            }
        }
        
        s[index++] = prev;
                
        if (count > 1) {
            int start = index;
            while (count > 0) {
                s[index++] = (count % 10) + '0';
                count /= 10;
            }
            std::reverse(s.begin() + start, s.begin() + index);
        }
        
        return index;
    }
};

    