#ifndef MERGESORT_H
#define MERGESORT_H

#include<vector>
using namespace std;
class MergeSort{
    private:
        vector<int> *nums;

    public:
        MergeSort(vector<int> *nums);
        ~MergeSort();
        void sort();
        void recursiveSort(int left , int right);
    
};

#endif