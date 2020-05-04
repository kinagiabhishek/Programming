class Solution {
public:
    int findComplement(int num) {
        vector<int> binaryRep;
        int ans=0;
        if(num==0)
            return 1;
        else{
            while(num>0){
                binaryRep.push_back((num%2)^1);
                num/=2;
            }
        }
        for(int i=0;i<binaryRep.size();++i)
            ans+=(binaryRep[i]*pow(2,i));
        return ans;
    }
};