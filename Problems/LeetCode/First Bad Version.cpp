//Returns if the version is bad.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,r=n,fb=1;
        while(l<=r){
            int m=l+((r-l)/2);
            if(isBadVersion(m)){
                if(m==1 || (!isBadVersion(m-1))){
                    fb=m;
                    break;
                }else{
                    r=m-1;
                }
            }else{
                l=m+1;
            }
        }
        return fb;
    }
};