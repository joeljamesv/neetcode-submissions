class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<vector<int>> retList;

        std::unordered_map<int, int> binary;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            binary.insert({(1 << i), nums[i]});
        }

        int m;
        int number;
        std::vector<int> subList;
        for (int i = 0; i < (1 << n); i++) {
            m = n - 1;
            number = i;
            subList = {};
            while (m >= 0) {
                if (number / (1 << m) >= 1) {
                    subList.push_back(binary[(1 << m)]);
                    number = number - (1 << m);
                }
                m--;
            }
            retList.push_back(subList);
        }

        return retList;
    }
};
