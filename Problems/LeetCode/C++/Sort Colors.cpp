#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0{0},count1{0},count2{0},i{0};
        for(int n:nums){
            if(n==0){
                count0++;
            }
            else if(n==1){
                count1++;
            }
            else{
                count2++;
            }
        }
        for(int j=0;j<count0;i++,j++)
            nums[i]=0;
        for(int j=0;j<count0;i++,j++)
            nums[i]=1;
        for(int j=0;j<count0;i++,j++)
            nums[i]=2;
    }
};