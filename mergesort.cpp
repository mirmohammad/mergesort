// File:    mergesort.cpp
// Author:  Mirmohammad Saadati
// Desc:    Merge Sort with in-place merge

#include <iostream>
using namespace std;

// Size of array
#define N 10

// In-place merge
void merge(int n[], int left, int middle, int right) {
    int half1 = middle - left + 1;
    int half2 = right - middle;
    int LEFT[half1], RIGHT[half2];
    for(int i = 0; i < half1; i++) // copy the first half
        LEFT[i] = n[left + i];
    for(int i = 0; i < half2; i++) // copy the second half
        RIGHT[i] = n[middle + 1 + i];
    for(int i = 0, j = 0, k = left; k <= right; k++)
        if(i < half1 && j < half2)
            if(LEFT[i] <= RIGHT[j]) // asc or dec
                n[k] = LEFT[i++];
            else
                n[k] = RIGHT[j++];
        else
            if(i < half1)
                n[k] = LEFT[i++];
            else
                n[k] = RIGHT[j++];
}

void mergeSort(int n[], int left, int right) {
    if(left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(n, left, middle);
        mergeSort(n, middle + 1, right);
        merge(n, left, middle, right);
    }

}

int main() {
    int arr[N] = {1, 4, 8, 7, 9, 2, 6, 0, 3, 5};
    mergeSort(arr, 0, N - 1);
    for(int i = 0; i < N || !(cout << endl); i++)
        cout << arr[i] << ", ";
    return 0;
}
