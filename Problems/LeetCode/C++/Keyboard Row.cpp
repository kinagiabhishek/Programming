#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        set<char> r1={'q','w','e','r','t','y','u','i','o','p'};
        set<char> r2={'a','s','d','f','g','h','j','k','l'};
        set<char> r3={'z','x','c','v','b','n','m'};
        for(string s:words){
            int c1=0,c2=0,c3=0;
            for(char c:s){
                if(r1.find(tolower(c)) != r1.end())
                    c1++;
                else if(r2.find(tolower(c)) != r2.end())
                    c2++;
                else if(r3.find(tolower(c)) != r3.end())
                    c3++;
            }
            if(c1==s.length() || c2==s.length() || c3==s.length())
                res.push_back(s);
        }
        return res;
    }
};