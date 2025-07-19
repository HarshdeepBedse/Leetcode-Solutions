class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // Count the number of set bits in num2
        int k = 0;
        while (num2 > 0) {
            k += (num2 & 1);
            num2 >>= 1;
        }

        int x = 0;

        // Set bits from num1
        for (int i = 31; i >= 0; --i) {
            if (k == 0) break;
            if (num1 & (1 << i)) {
                x |= (1 << i); // Add this bit to x
                --k;
            }
        }

        // Add remaining bits from the least significant positions
        for (int i = 0; i < 32; ++i) {
            if (k == 0) break;
            if (!(x & (1 << i))) {
                x |= (1 << i); // Add this bit to x
                --k;
            }
        }

        return x;
    }
};