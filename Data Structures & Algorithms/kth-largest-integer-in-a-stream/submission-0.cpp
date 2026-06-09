class KthLargest {
    std::map<int, int> hash;
    int n;

   public:
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) != hash.end()) {
                hash[nums[i]]++;
            } else {
                hash.insert({nums[i], 1});
            }
        }

        for (auto [x, y] : hash) {
            std::cout << x << " " << y << std::endl;
        }
    }

    int add(int val) {
        std::cout << "******" << std::endl;
        if (hash.find(val) != hash.end()) {
            hash[val]++;
        } else {
            hash.insert({val, 1});
        }

        for (auto [x, y] : hash) {
            std::cout << x << " " << y << std::endl;
        }

        std::cout << "xxxxx" << std::endl;

        auto it = std::prev(hash.end());
        std::cout << it->first << " " << it->second << std::endl;
        int toK = n;
        std::cout << toK << std::endl;
        while (toK > 0) {
            std::cout << it->first << std::endl;
            std::cout << it->second << std::endl;

            if (toK > it->second) {
                toK = toK - it->second;
                if (it->second == 1)
                    it = std::prev(it);
                else {
                    it = std::prev(it, it->second - 1);
                }
            } else
                break;
        }
        return it->first;
    }
};
