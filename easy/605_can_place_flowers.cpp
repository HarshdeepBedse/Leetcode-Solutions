#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        for (int i = 0; i < size; ++i) {
         
            if (flowerbed[i] == 0) {
              
                bool leftEmpty = (i == 0 || flowerbed[i - 1] == 0);
                bool rightEmpty = (i == size - 1 || flowerbed[i + 1] == 0);

                if (leftEmpty && rightEmpty) {
                    
                    flowerbed[i] = 1;
                    n--;

                    
                    if (n == 0) {
                        return true;
                    }
                }
            }
        }

        // If we exit the loop and still have flowers left to plant, return false
        return n <= 0;
    }
};