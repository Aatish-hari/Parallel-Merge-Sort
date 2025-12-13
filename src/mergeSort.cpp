#include"mergeSort.hpp"
#include<cstdlib>
#include<iostream>
using namespace std;

MergeSort::MergeSort(vector<int> *nums){
    this->nums = nums;
}

MergeSort::~MergeSort(){

}

void MergeSort::recursiveSort(int left , int right){
    if(left>=right){
        return;
    }

    int mid = left + (right-left)/2;

    recursiveSort(left , mid);
    recursiveSort(mid+1 , right);

    vector<int> ans;

    int i = left;
    int j = mid+1;

    while(i<=mid && j<=right){
        if((*nums)[i]<=(*nums)[j]){
        ans.push_back((*nums)[i]);
        i++;
        }
        else{
            ans.push_back((*nums)[j]);
            j++;
        }
    }

    while(i<=mid){
        ans.push_back((*nums)[i]);
        i++;
    }
    while(j<=right){
        ans.push_back((*nums)[j]);
        j++;
    }

    for(int k = 0 ; k<ans.size() ; k++){    //.....
        (*nums)[left+k] = ans[k];
    }

    return ;
}

void MergeSort::sort(){
    if((*nums).size() == 0){
        exit(1);
    }
    recursiveSort(0 , (*nums).size()-1);
   
}