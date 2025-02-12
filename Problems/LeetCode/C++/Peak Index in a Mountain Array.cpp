#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l=0,r=A.size()-1,m;
        while(l<=r){
            m=l+((r-l)/2);
            if(A[m]>A[m-1] && A[m]>A[m+1])
                return m;
            else if(A[m]>A[m-1] && A[m]<A[m+1])
                l=m+1;
            else
                r=m-1;
        }
        return -1;
    }
};