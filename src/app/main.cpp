#include<iostream>
#include<vector>
#include<chrono>
#include"sorting/mergeSort.hpp"
#include"sorting/parallelmergeSort.hpp"

using namespace std;

int main(int argc , char *argv[]){
    const int size = 10000000;
    vector<int> nums(size);
    vector<int> nums1(size);

    for(int i = 0 ; i<size ; i++){
        nums[i] = rand()%1000;
        nums1[i]=rand()%1000;
    }

    MergeSort* mergesort = new MergeSort(&nums);

    auto starttimer = chrono::high_resolution_clock::now();
    mergesort->sort();
    auto endtimer = chrono::high_resolution_clock::now();
    chrono::duration<double> mergesortduration = endtimer - starttimer;
    cout<<"Time taken by Merge sort algorithm: "<<mergesortduration.count()<<" seconds"<<endl;

    delete mergesort;


    ParallelMergeSort* parallelmergesort = new ParallelMergeSort(&nums);

    starttimer = chrono::high_resolution_clock::now();
    parallelmergesort->sort();
    endtimer = chrono::high_resolution_clock::now();
    mergesortduration = endtimer - starttimer;
    cout<<"Time taken by Parallel Merge sort algorithm: "<<mergesortduration.count()<<" seconds"<<endl;

    delete parallelmergesort;
    
}
