#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool customSort(vector<int> a, vector<int> b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),customSort);
        vector<vector<int>> que(people.size(),vector<int>());
        for(auto v:people){
            int size=v[1];
            for(auto& w:que){
                if(!(w.size() && w[0]<v[0])){
                    if(!size){
                        w.push_back(v[0]);
                        w.push_back(v[1]);
                        break;
                    }else{
                        size--;
                    }
                }
            }
        }
        return que;
    }
};