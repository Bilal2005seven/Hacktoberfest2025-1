class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()); // min capacity = heaviest package
        int high = accumulate(weights.begin(), weights.end(), 0); // max capacity = sum of all packages

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canShip(weights, days, mid)) {
                high = mid; // mid works, try smaller
            } else {
                low = mid + 1; // mid too small, need bigger
            }
        }
        return low;
    }

private:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int neededDays = 1, currentLoad = 0;
        for (int w : weights) {
            if (currentLoad + w > capacity) {
                neededDays++;
                currentLoad = 0;
            }
            currentLoad += w;
        }
        return neededDays <= days;
    }
};
