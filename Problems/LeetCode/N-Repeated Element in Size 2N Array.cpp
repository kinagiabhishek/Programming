#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int N=A.size()/2;
        unordered_map<int,int> hash;
        for(int i:A){
            hash[i]++;
        }
        for(auto i=hash.begin();i!=hash.end();++i)
            if(i->second==N)
                return i->first;
        return -1;
    }
};