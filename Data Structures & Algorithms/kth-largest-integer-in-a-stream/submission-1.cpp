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
    }

    int add(int val) {
        if (hash.find(val) != hash.end()) {
            hash[val]++;
        } else {
            hash.insert({val, 1});
        }

        auto it = std::prev(hash.end());
        int toK = n;
        while (toK > 0) {
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
