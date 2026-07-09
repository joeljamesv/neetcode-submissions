class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        std::vector<string> shutup;

        if (digits.size() == 0) return shutup;
        std::unordered_map<int, string> hash;
        std::queue<string> retList;
        const int n = digits.size();

        hash.insert({2, "abc"});
        hash.insert({3, "def"});
        hash.insert({4, "ghi"});
        hash.insert({5, "jkl"});
        hash.insert({6, "mno"});
        hash.insert({7, "pqrs"});
        hash.insert({8, "tuv"});
        hash.insert({9, "wxyz"});

        int currentSize;
        int hashKey;
        for (int i = 0; i < digits.size(); i++) {
            currentSize = i + 1;
            hashKey = digits[i] - '0';
            if (retList.empty()) {
                for (int j = 0; j < hash[hashKey].size(); j++) {
                    retList.push(std::string(1, hash[hashKey][j]));
                }
            } else {
                while (1) {
                    std::string queueFront = retList.front();
                    if (queueFront.size() != currentSize) {
                        for (int j = 0; j < hash[hashKey].size(); j++) {
                            std::string toAdd = queueFront + std::string(1, hash[hashKey][j]);
                            retList.push(toAdd);
                        }
                        retList.pop();
                    } else {
                        break;
                    }
                }
            }
        }
        while (!retList.empty()) {
            shutup.push_back(retList.front());
            retList.pop();
        }
        return shutup;
    }
};
