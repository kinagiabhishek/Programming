class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trusted(1001,0);
        unordered_map<int,bool> trustMap;
        for(int i=0;i<trust.size();++i){
            trustMap[trust[i][0]]=true;
            trusted[trust[i][1]]++;
        }
        for(int i=1;i<=N;++i)
            if(trusted[i]==N-1 && trustMap.find(i)==trustMap.end())
                return i;
        return -1;
    }
};