#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canEvenPermute(string s){
        unordered_map<char,int> hash;
        for(char c:s){
            hash[c]++;
        }
        for(auto i:hash)
            if((i.second)%2!=0)
                return false;
        return true;
    }
    bool canOddPermute(string s){
        int oddCount=0;
        unordered_map<char,int> hash;
        for(char c:s){
            hash[c]++;
        }
        for(auto i:hash)
            if((i.second)%2!=0)
                oddCount++;
        if(oddCount==1){
            return true;
        }else{
            return false;
        }
    }
    bool canPermutePalindrome(string s) {
        if(s.length()%2==0){
            return canEvenPermute(s);
        }else{
            return canOddPermute(s);
        }
    }
};