#include"parallelmergeSort.hpp"
#include<iostream>
#include<thread>
#include<algorithm>
using namespace std;

ParallelMergeSort::ParallelMergeSort(vector<int> *nums){
    this->nums = nums;
}

ParallelMergeSort::~ParallelMergeSort(){}

void ParallelMergeSort::recursiveSort(int left , int right){
    
    int threshold = 5000;
    if(right - left <threshold){
        std::sort( nums->begin()+left , nums->begin()+right+1);  // .... std cause i already have sort() func.
        return;
    }
    if(left>=right){
        return;
    }

    int mid = left + (right-left)/2;

    thread thread1([this , left ,mid](){this->recursiveSort(left , mid);});
    thread thread2([this , mid ,right](){this->recursiveSort(mid+1 , right);});
    thread1.join();
    thread2.join();
   
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

void ParallelMergeSort::sort(){
    if((*nums).size() == 0){
        return;
    }
    thread thread1([this](){recursiveSort(0 , (*nums).size()-1);});
    thread1.join();
}