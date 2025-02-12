#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool customSort(vector<int> a, vector<int> b){
        return (a[0]-a[1]<b[0]-b[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int tot=0;
        sort(costs.begin(),costs.end(),customSort);
        for(int i=0;i<(costs.size())/2;++i)
            tot+=costs[i][0]+costs[i+(costs.size()/2)][1];
        return tot;
    }
};