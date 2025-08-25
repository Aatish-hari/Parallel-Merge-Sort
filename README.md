# **⚡ Parallel Merge Sort vs Classic Merge Sort**

This project compares the performance of normal Merge Sort and a Parallel Merge Sort implemented in C++.

## **❌ What is the issue?**

Classic Merge Sort only runs on one CPU core.
For very large datasets, this makes it slow because modern CPUs have multiple cores that are not being used.

## **✅ What is improved?**

A Parallel Merge Sort is implemented using C++ threads.
It divides the work and sorts parts of the array at the same time on multiple cores.

## **📊 How much is improved?**

On a dataset of 10,000,000 integers:

![image alt](https://github.com/Aatish-hari/Parallel-Merge-Sort/blob/f993d07cdba6af51473cb54826ef064626790205/time%20difference.png)

## **🚀 That’s about a 9x speed improvement!**

(**Note**:- this project is implemented on machine with 8 core and 12 logical processors, the time may differ for different machines)

## **⚙️ How is it improved?**

-The array is divided into halves recursively.

-Instead of sorting halves sequentially, they are sorted in parallel threads.

-After sorting, the halves are merged together.

A threshold is used: if the part is too small, normal sorting is used to avoid thread overhead.

# **✨ This project shows how parallel programming can greatly improve algorithm performance on modern multi-core CPUs.**
