#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED
#include<bits/stdc++.h>

// The hash table class
// it consist of functions and variables
class HashMap {
    long long int data;
    std::list<long long int> *table;
public:
    int N;
    HashMap(int N);
    void PrintHashMap();
    int FoldingFunc(long long int key);
    int MiddleSquaringFunc(long long int key);
    int TruncationFunc(long long int key);

    void FoldingInsert(long long int key);
    void MiddleSquaringInsert(long long int key);
    void TruncationInsert(long long int key);

    int FoldingSearch(long long int key);
    int MiddleSquaringSearch(long long int key);
    int TruncationSearch(long long int key);

    void FoldingRemove(long long int key);
    void MiddleSquaringRemove(long long int key);
    void TruncationRemove(long long int key);
};

#endif // CLASS_H_INCLUDED
