class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        std::array<int, 26> frequency;
        frequency.fill(0);
        std::array<int, 26> lastIndex;
        lastIndex.fill(-2);

        for (int i = 0; i < tasks.size(); i++) {
            frequency[int(tasks[i]) - 65]++;
            lastIndex[int(tasks[i]) - 65] = -1;
        }

        int index = 0;
        int maxPosition;
        int max;
        int flag;

        while (1) {
            max = 0;
            flag = 0;

            for (int i = 0; i < 26; i++) {
                if (lastIndex[i] != -2 && (lastIndex[i] == -1 || index > (lastIndex[i] + n))) {
                    if (frequency[i] > max) {
                        flag = 1;
                        max = frequency[i];
                        maxPosition = i;
                    }
                }
            }

            if (flag != 0) {
                frequency[maxPosition]--;
                lastIndex[maxPosition] = index;
            }

            index++;

            int tasksLeft = 0;
            for (int i = 0; i < 26; i++) {
                tasksLeft += frequency[i];
            }
            if (tasksLeft == 0) break;
        }
        return index;
    }
};