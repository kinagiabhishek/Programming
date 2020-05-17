#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    inline int summation(int n){
        return ((n*(n+1))/2); 
    }
    int countLetters(string S) {
        int ans=0;
        vector<int> maxDistinct;
        for(int i=0;i<S.size();){
            int c=1;
            i++;
            while(i<S.size() && S[i]==S[i-1])i++,c++;
            maxDistinct.push_back(c);
        }
        for(int i=0;i<maxDistinct.size();++i)
            ans+=summation(maxDistinct[i]);
        return ans;
    }
};