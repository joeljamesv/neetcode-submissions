class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        std::vector<int> alps(26, 0);
        std::vector<int> apes(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            alps[(int)s1[i] - 97]++;
            apes[(int)s2[i] - 97]++;
        }
        auto lamb = [](const std::vector<int>& alps, const std::vector<int>& apes) {
            for (int i = 0; i < 26; i++) {
                if (alps[i] != apes[i]) {
                    return false;
                }
            }
            return true;
        };

        if (lamb(alps, apes)) return true;

        for (int i = s1.size(); i < s2.size(); i++) {
            apes[(int)s2[i - s1.size()] - 97]--;
            apes[(int)s2[i] - 97]++;

            if (lamb(alps, apes)) return true;
        }

        return false;
    }
};
