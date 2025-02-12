#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximum69Number (int num) {
        stack<int> stk;
        int ans=0;
        while(num>0){
            stk.push(num%10);
            num/=10;
        }
        while(!stk.empty() && stk.top()==9){
            ans=ans*10+stk.top();
            stk.pop();
        }
        if(stk.empty())
            return ans;
        stk.pop();
        ans=ans*10+9;
        while(!stk.empty()){
            ans=ans*10+stk.top();
            stk.pop();
        }
        return ans;
    }
};