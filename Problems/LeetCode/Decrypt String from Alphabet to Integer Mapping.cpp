#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string freqAlphabets(string s) {
        string res="";
        for(int i=0;i<s.length();++i){
            if(i+2<s.length() && s[i+2]=='#'){
                res+=( ((s[i]-'0')*10) + s[i+1]-'1'+'a');
                i+=2;
            }else{
                res+=(s[i]-'1'+'a');
            }
        }
        return res;
    }
};