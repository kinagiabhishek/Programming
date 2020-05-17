class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count=0;
        unordered_map<char,bool> hash;
        for(char c:J)
            hash[c]=true;
        for(char c:S){
            if(hash[c])
                count++;
        }
        return count;
    }
};