#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int w1=-1,w2=-1,minDist=INT_MAX;
        for(int i=0;i<words.size();++i){
            if(words[i]==word1)
                w1=i;
            if(words[i]==word2)
                w2=i;
            if(w1!=-1 && w2!=-1 && abs(w1-w2)<minDist)
                minDist=abs(w1-w2);
        }
        return minDist;
    }
};