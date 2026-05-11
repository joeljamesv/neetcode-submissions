class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        std::set<int> returnSet;

        for(int i=0;i<nums.size();i++)
        {
            returnSet.insert(nums[i]);
        }

        if(returnSet.size() == nums.size())
            return false;
        else
            return true;
        
    }
};