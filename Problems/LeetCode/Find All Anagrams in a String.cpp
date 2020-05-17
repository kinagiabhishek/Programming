#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> smap(26,0),pmap(26,0),result;
        if(s.size()<p.size()) return result;
        for(int i=0;i<p.size();++i){
            smap[s[i]-'a']++;
            pmap[p[i]-'a']++;
        }
        if(smap == pmap)
            result.push_back(0);
        for(int i=p.size();i<s.size();++i){
            smap[s[i]-'a']++;
            smap[s[i-p.size()]-'a']--;
            if(smap == pmap) result.push_back(i-p.size()+1);
        }
        return result;
    }
};