#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(),-1);
        for(int i=0;i<graph.size();++i){
            if(colors[i]==-1){
                stack<int> s;
                s.push(i);
                colors[i]=0;
                while(!s.empty()){
                    int top=s.top();
                    s.pop();
                    for(int j=0;j<graph[top].size();++j){
                        if(colors[graph[top][j]]==-1){
                            colors[graph[top][j]]=colors[top]^1;
                            s.push(graph[top][j]);
                        } else if(colors[graph[top][j]]==colors[top]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N);
        // Constructing an undirected graph, to test for bi-partition
        for(vector<int> v:dislikes){
            graph[v[0]-1].push_back(v[1]-1);
            graph[v[1]-1].push_back(v[0]-1);
        }
        return isBipartite(graph);
    }
};