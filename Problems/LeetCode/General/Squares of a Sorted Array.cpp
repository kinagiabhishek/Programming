#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        //Time:O(Nlog(N)) Space:O(N)
        for(int i=0;i<A.size();++i)
            A[i]*=A[i];
        sort(A.begin(),A.end());
        return A;
        //Time:O(N) Space:O(N)
        int ind=-1,l=0,r=A.size()-1,m;
        vector<int> negArray;
        vector<int> posArray;
        while(l<=r){
            m=l+((r-l)/2);
            if(A[m]<0){
                if(m==A.size()-1 || (m+1<A.size() && A[m+1]>=0) ){
                    ind=m;
                    break;
                }else{
                    l=m+1;
                }
            }else{
                r=m-1;
            }
        }
        for(int i=ind;i>=0;i--){
            negArray.push_back(A[i]*A[i]);
        }
        for(int i=ind+1;i<A.size();i++){
            posArray.push_back(A[i]*A[i]);
        }
        int n=0,p=0,k=0;
        while(n<negArray.size() && p<posArray.size()){
            if(negArray[n]<posArray[p]){
                A[k++]=negArray[n++];
            }else{
                A[k++]=posArray[p++];
            }
        }
        while(n<negArray.size())
            A[k++]=negArray[n++];
        while(p<posArray.size())
            A[k++]=posArray[p++];
        return A;    
    }
};