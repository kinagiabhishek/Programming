#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Sort{
public:
    void print(vector<int> nums){
        for(int i:nums)
            cout<<i<<" ";
        cout<<endl;
    }
    void bubbleSort(vector<int> nums){
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<nums.size()-i-1;j++){
                if(nums[j]>nums[j+1])
                    swap(nums[j],nums[j+1]);
            }
        }
        print(nums);
    }
    void selectionSort(vector<int> nums){
    }
    void insertionSort(vector<int> nums){
    }
    void mergeSort(vector<int> nums){
    }
    void quickSort(vector<int> nums,int l,int r){
        if(l<r){
            int p=partitionQ(nums,l,r);
            quickSort(nums,l,p-1);
            quickSort(nums,p+1,r);
        }
    }
    int partitionQ(vector<int> nums,int l,int r){
        int pivot=nums[r];
        int index=l-1;
        for(int i=l;i<r;i++){
            if(nums[i]<pivot){
                index++;
                swap(&nums[i],&nums[index]);
            }
        }
        swap(&nums[i+1],&nums[r]);
        return i+1;
    }
    void quickSort(vector<int> nums){
        quickSort(nums,0,nums.size()-1);
        print(nums);
    }
    void heapSort(vector<int> nums){
    }
};
int main()
{
    vector<int> nums={5,2,1,4,3,7,9,6,8,10};
    Sort s;
    //s.bubbleSort(nums);
    s.quickSort(nums);
    return 0;
}
