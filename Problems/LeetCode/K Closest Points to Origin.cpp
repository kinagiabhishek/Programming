#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        if(points.size()==1){
            result.push_back(points[0]);
            return result;  
        }
        vector<int> dist(points.size());
        for(int i=0;i<dist.size();++i)
            dist[i]=(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
        sort(dist.begin(),dist.end());
        int kdist=dist[K-1];
        for(int i=0;i<points.size();++i)
            if((points[i][0]*points[i][0] + points[i][1]*points[i][1]) <= kdist)
                result.push_back(points[i]);
        return result;
    }
};