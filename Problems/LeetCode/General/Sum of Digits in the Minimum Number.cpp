#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int minEle=*min_element(A.begin(),A.end());
        int sum=0;
        while(minEle>0){
            sum+=minEle%10;
            minEle/=10;
        }
        if(sum%2==0)
            return 1;
        else
            return 0;
    }
};