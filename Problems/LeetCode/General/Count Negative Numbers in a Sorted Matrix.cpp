#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        //O(mlog(n))
        int m=grid.size(),n=grid[0].size(),count=0;
        for(int i=0;i<m;++i){
            int l=0,r=n-1,ans=n,m;
            while(l<=r){
                m=l+((r-l)/2);
                if(grid[i][m]<0){
                    if(m==0 || (m>0 && grid[i][m-1]>=0)){
                        ans=m;
                        break;
                    }else{
                        r=m-1;
                    }
                }else{
                    l=m+1;
                }
            }
            count+=n-ans;
        }
        return count;
        //O(M+N)
        int M(grid.size()),N(grid[0].size()),r(0),c(N-1),ans(0);
        while(r<M){
            while(c>=0 && grid[r][c]<0)c--;
            ans+=N-c-1;
            r++;
        }
        return ans;
    }
};