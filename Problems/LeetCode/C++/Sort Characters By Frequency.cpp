#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> hash;
        map<int,vector<char>> revHash;
        string res;
        for(char c:s)
            hash[c]++;
        for(auto i=hash.begin();i!=hash.end();++i)
            revHash[i->second].push_back(i->first);
        for(auto i=revHash.rbegin();i!=revHash.rend();++i)
            for(char c:i->second)
                for(int j=0;j<i->first;++j)
                    res+=c;
        return res;
    }
};