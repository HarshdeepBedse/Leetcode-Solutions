#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap;
        int maxSum = -1;

        for (int num : nums) {
            int sumDigits = getDigitSum(num);

            // If a number with this digit sum exists, calculate the sum
            if (digitSumMap.find(sumDigits) != digitSumMap.end()) {
                maxSum = max(maxSum, num + digitSumMap[sumDigits]);
            }
            
            // Update the max number for this digit sum
            digitSumMap[sumDigits] = max(digitSumMap[sumDigits], num);
        }

        return maxSum;
    }
};