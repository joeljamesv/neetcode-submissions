class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        std::unordered_map<int,int> hash;
        std::vector<int> retVal{0,0};

        for(int i=0;i<nums.size();i++)
        {
            if(hash.find(target-nums[i]) == hash.end())
            {
                hash.insert({nums[i],i});
            }
            else
            {
                retVal[0]=hash[target-nums[i]];
                retVal[1]=i;
            }
        }
        return retVal;
        
    }
};
