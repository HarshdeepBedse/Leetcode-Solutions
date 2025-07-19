class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;

        double result = log2(n)/2;
    return floor(result)==result;
    }
};