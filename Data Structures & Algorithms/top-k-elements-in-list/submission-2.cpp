class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int maxFrequency = nums.size();
        std::unordered_map<int, int> hash;
        std::vector<int> retList(k,0);
        for (int i = 0; i < maxFrequency; i++) {
            if (hash.find(nums[i]) != hash.end()) {
                hash[nums[i]]++;
            } else
                hash.insert({nums[i], 1});
        }
        
        int maxValue;
        int maxKey;
        for(int i=0;i<k;i++)
        {
            maxValue = 0;
            for(auto &[key,value] : hash)
            {
                if(value > maxValue)
                {
                    maxValue = value;
                    maxKey = key;
                }
            }
            retList[i] = maxKey;
            hash[maxKey]=0;
        }
        return retList;
    }
};
