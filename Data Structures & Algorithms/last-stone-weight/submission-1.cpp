class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1) return stones[0];

        if (stones.size() == 2)
            return stones[0] - stones[1] > 0 ? stones[0] - stones[1] : -1 * (stones[0] - stones[1]);

        while (1) {
            for (int x = std::floor(stones.size() / 2) - 1; x >= 0; x--) {
                heapify(stones, x);
            }

            int secondLargestIdx = 1;
            if (stones[2] > stones[1]) {
                secondLargestIdx = 2;
            }
            if (stones[secondLargestIdx] == 0) return stones[0];

            stones[0] = stones[0] - stones[secondLargestIdx];
            stones[secondLargestIdx] = 0;
        }
    }

    void heapify(std::vector<int>& stones, int i) {
        int largest = i;
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;

        if (stones.size() > leftIndex && stones[leftIndex] > stones[largest]) {
            largest = leftIndex;
        }
        if (stones.size() > rightIndex && stones[rightIndex] > stones[largest]) {
            largest = rightIndex;
        }

        if (largest != i) {
            std::swap(stones[i], stones[largest]);
            heapify(stones, largest);
        }
    }
};
