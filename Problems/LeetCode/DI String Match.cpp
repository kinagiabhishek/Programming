#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> diStringMatch(string S) {
        deque<int> deck(S.length()+1);
        vector<int> res;
        for(int i=0;i<deck.size();++i)
            deck[i]=i;
        for(char c:S){
            if(c=='D'){
                res.push_back(deck.back());
                deck.pop_back();
            }else{
                res.push_back(deck.front());
                deck.pop_front();
            }
        }
        res.push_back(deck.front());
        deck.pop_front();
        return res;
    }
};