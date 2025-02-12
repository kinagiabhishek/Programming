#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isEmpty(vector<int> v){
        for(int i:v)
            if(i!=0)
                return false;
        return true;
    }
    string sortString(string s) {
        string res="";
        vector<int> v(26,0);
        for(char c:s)
            v[c-'a']++;
        while(!isEmpty(v)){
            for(int i=0;i<26;++i){
                if(v[i]>0){
                    res+=(i+'a');
                    v[i]--;
                }
            }
            for(int i=25;i>=0;--i){
                if(v[i]>0){
                    res+=(i+'a');
                    v[i]--;
                }
            }
        }
        return res;
    }
};