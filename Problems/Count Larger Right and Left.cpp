class Solution {
public:
    void mergeModifyL(vector<int>& nums,int l,int r,unordered_map<int,int>& count){
        if(l>=r){
            return;
        }
        int m = l+((r-l)/2);
        mergeModifyL(nums,l,m,count);
        mergeModifyL(nums,m+1,r,count);
        mergeL(nums,l,m,r,count);
    }
    void mergeL(vector<int>& nums,int l,int m,int r,unordered_map<int,int>& count){
        vector<int> tmp(r-l+1);
        int i=l,j=m+1,k=0,lc=0;
        while(i<=m && j<=r){
            if(nums[i]<nums[j]){
                tmp[k++]=nums[i++];
                lc++;
            }else{
                count[nums[j]]+=lc;
                tmp[k++]=nums[j++];
            }
        }
        while(i<=m){
            tmp[k++]=nums[i++];
        }
        while(j<=r){
            count[nums[j]]+=lc;
            tmp[k++]=nums[j++];
        }
        k=0;
        for(int i=l;i<=r;i++)
            nums[i]=tmp[k++];
    }
    void mergeModifyR(vector<int>& nums,int l,int r,unordered_map<int,int>& count){
        if(l>=r){
            return;
        }
        int m = l+((r-l)/2);
        mergeModifyR(nums,l,m,count);
        mergeModifyR(nums,m+1,r,count);
        mergeR(nums,l,m,r,count);
    }
    void mergeR(vector<int>& nums,int l,int m,int r,unordered_map<int,int>& count){
        vector<int> tmp(r-l+1);
        int i=l,j=m+1,k=0,rc=0;
        while(i<=m && j<=r){
            if(nums[i]<nums[j]){
                count[nums[i]]+=rc;
                tmp[k++]=nums[i++];
            }else{
                tmp[k++]=nums[j++];
                rc++;
            }
        }
        while(i<=m){
            count[nums[i]]+=rc;
            tmp[k++]=nums[i++];
        }
        while(j<=r){
            tmp[k++]=nums[j++];
        }
        k=0;
        for(int i=l;i<=r;i++)
            nums[i]=tmp[k++];
    }
    int countLargerRightAndLeft(vector<int>& rating) {
        unordered_map<int,int> countRight;
        unordered_map<int,int> countLeft;
        vector<int> dupRating(rating);
        vector<int> r1(rating);
        mergeModifyR(rating,0,rating.size()-1,countRight);
        mergeModifyL(dupRating,0,rating.size()-1,countLeft);
        for(int i:r1)
            cout<<countRight[i]<<" ";
        cout<<endl;
        for(int i:r1)
            cout<<countLeft[i]<<" ";
        cout<<endl;
        return 0;
    }
};