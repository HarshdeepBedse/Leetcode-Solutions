class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;

        double result = log2(n);
    return floor(result)==result;
}

};