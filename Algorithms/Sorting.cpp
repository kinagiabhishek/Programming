/**
 * Various Sorting Algorithms
 * Author : Abhishek Kinagi
 * Test : Commit
 */
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class SortUtil{
public:
    /**
     * Generic method to print out the array
     */
    void print(vector<int> nums){
        for(int i:nums)
            cout<<i<<" ";
        cout<<endl;
    }
    /**
     * Bubble Sort Method
     */
    void bubbleSort(vector<int> nums){
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<nums.size()-i-1;j++){
                if(nums[j]>nums[j+1])
                    swap(nums[j],nums[j+1]);
            }
        }
        print(nums);
    }
    /**
     * Selection Sort Method
     */
    void selectionSort(vector<int> nums){
        for(int i=0;i<nums.size()-1;i++){
            int minInd = i;
            for(int j=i+1;j<nums.size();++j)
                if(nums[j]<nums[minInd])
                    minInd=j;
            swap(nums[i],nums[minInd]);
        }
        print(nums);
    }
    /**
     * Insertion Sort Method
     */
    void insertionSort(vector<int> nums){
        for(int i=1;i<nums.size();i++){
            int curr = nums[i];
            int j=i-1;
            while(j>=0 && nums[j]>curr){
                nums[j+1]=nums[j];
                j--;
            }
            swap(nums[j+1],curr);
        }
        print(nums);
    }
    /**
     * Merge Sort Methods
     */
    void merge(vector<int>& nums,int l,int m,int r){
        vector<int> tmp(r-l+1,0);
        int i=l,j=m+1,k=0;
        while(i<=m && j<=r){
            if(nums[i]<nums[j]){
                tmp[k++]=nums[i++];
            }else{
                tmp[k++]=nums[j++];
            }
        }
        while(i<=m)
            tmp[k++]=nums[i++];
        while(j<=r)
            tmp[k++]=nums[j++];
        
        for(int p=0;p<tmp.size();++p){
            nums[l+p]=tmp[p];
        }
    }
    void mergeSort(vector<int>& nums,int l, int r){
        if(l<r){
            int m=l+((r-l)/2);
            mergeSort(nums,l,m);
            mergeSort(nums,m+1,r);
            merge(nums,l,m,r);
        }
    }
    void mergeSort(vector<int> nums){
        mergeSort(nums,0,nums.size()-1);
        print(nums);
    }
    /**
     * Quick Sort Methods
     */
    int partitionQ(vector<int>& nums,int l,int r){
        int pivot=nums[r];
        int index=l-1;
        for(int i=l;i<r;i++){
            if(nums[i]<pivot){
                index++;
                swap(nums[i],nums[index]);
            }
        }
        swap(nums[index+1],nums[r]);
        return index+1;
    }
    void quickSort(vector<int>& nums,int l,int r){
        if(l<r){
            int p=partitionQ(nums,l,r);
            quickSort(nums,l,p-1);
            quickSort(nums,p+1,r);
        }
    }
    void quickSort(vector<int> nums){
        quickSort(nums,0,nums.size()-1);
        print(nums);
    }
    /**
     * Heap Sort Methods
     */
    void heapSort(vector<int> nums){
    }
};
int main()
{
    //Test Vector to be sorted
    vector<int> nums={5,2,1,4,3,7,9,6,8,10};
    
    //Initialize the sort util class object
    SortUtil s;
    
    //Apply the sorting algorithms
    cout<<"Bubble Sort"<<endl;
    s.bubbleSort(nums);
    
    cout<<"Quick Sort"<<endl;
    s.quickSort(nums);
    
    cout<<"Merge Sort"<<endl;
    s.mergeSort(nums);

    cout<<"Selection Sort"<<endl;
    s.selectionSort(nums);
    
    cout<<"Insertion Sort"<<endl;
    s.insertionSort(nums);
    return 0;
}