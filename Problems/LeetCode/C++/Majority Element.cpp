class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int num:nums)
            hash[num]++;
        for(auto i=hash.begin();i!=hash.end();++i){
            if(i->second>(nums.size()/2))
                return i->first;
        }
        return -1;
    }
};