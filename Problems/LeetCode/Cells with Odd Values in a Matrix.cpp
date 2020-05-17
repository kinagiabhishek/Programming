#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int ans=0;
        vector<int> row(n,0);
        vector<int> column(m,0);
        for(int i=0;i<indices.size();++i){
            row[indices[i][0]]++;
            column[indices[i][1]]++;
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if((row[i]+column[j])%2!=0)
                    ans++;
            }
        }
        return ans;
    }
};