class Solution {
public:
    bool isAnagram(string s, string t) {
        std::vector<int> alphabets(26,0);

        int tSize = t.size();
        int sSize = s.size();

        if(tSize!=sSize)
            return false;

        int i;
        for(i=0;i<sSize;i++)
        {
            alphabets[int(s[i])-97]++;
        }

        for(i=0;i<tSize;i++)
        {
            alphabets[int(t[i])-97]--;
        }

        for(i=0;i<26;i++)
        {
            if(alphabets[i]!=0)
                return false;
        }
        return true;


        
    }
};
