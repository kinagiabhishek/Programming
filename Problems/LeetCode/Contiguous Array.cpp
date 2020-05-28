#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count=0,maxlen=0;
        unordered_map<int,int> hash;
        hash[0]=-1;
        for(int i=0;i<nums.size();++i){
            count=count+(nums[i]==1?1:-1);
            if(hash.find(count)!=hash.end()){
                maxlen=max(maxlen,i-hash[count]);
            }else{
                hash[count]=i;
            }
        }
        return maxlen;
    }
};