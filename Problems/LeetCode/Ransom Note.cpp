class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> ransom(26,0);
        for(char c:ransomNote)
            ransom[c-'a']++;
        for(char c:magazine)
            if(ransom[c-'a']>0)
                ransom[c-'a']--;
        for(int i:ransom)
            if(i>0)
                return false;
        return true;
    }
};