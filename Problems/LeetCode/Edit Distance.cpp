#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        if (n*m==0) return n+m;
        word1='0'+word1;
        word2='0'+word2;
        vector<vector<int>> minD(n+1,vector<int>(m+1));
        minD[0][0]=0;
        for(int i=1;i<n+1;++i)
            minD[i][0]=i;
        for(int i=1;i<m+1;++i)
            minD[0][i]=i;
        for(int i=1;i<n+1;i++)
            for(int j=1;j<m+1;j++)
                if(word1[i]==word2[j])
                    minD[i][j]=1+min(minD[i-1][j-1]-1,min(minD[i-1][j],minD[i][j-1]));
                else
                    minD[i][j]=1+min(minD[i-1][j-1],min(minD[i-1][j],minD[i][j-1]));
        return minD[n][m];
    }
};