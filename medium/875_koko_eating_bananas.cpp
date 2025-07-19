class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canEatAll(piles, h, mid)) {
                right = mid; // Try a smaller k
            } else {
                left = mid + 1; // Increase k
            }
        }
        return left; // The minimum speed that allows finishing within h hours
    }


    bool canEatAll(const vector<int>& piles, int h, int k) {
        int hoursNeeded = 0;
        for (int pile : piles) {
            hoursNeeded += ceil((double)pile / k);
        }
        return hoursNeeded <= h;
    }
};