class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int numSize = nums.size();

        std::vector<int> ans(2*numSize,0);

        int k=0;
        for(int i=0;i<ans.size();i++)
        {
            ans[i]=nums[k];
            k++;
            if(k==numSize)
                k=0;
        }
        return ans;
    }
};