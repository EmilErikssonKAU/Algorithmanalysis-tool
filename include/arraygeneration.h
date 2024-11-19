#ifndef ARRAYGENERATION_H
#define ARRAYGENERATION_H

typedef struct {
    int* array;
    int element;
} array_and_value;

int* getBestCaseBubbleSort(int size);

int* getWorstCaseBubbleSort(int size);

int* getBestCaseInsertionSort(int size);

int* getWorstCaseInsertionSort(int size);

int* getBestCaseQuickSortHigh(int size);

int* getWorstCaseQuickSortHigh(int size);

int* getSortedAscendingArray(int size);

int* getSortedDescendingArray(int size);

int* getRandomizedArray(int size);

array_and_value* getBestCaseLinearSearch(int size);

array_and_value* getWorstCaseLinearSearch(int size);

array_and_value* getBestCaseBinarySearch(int size);

array_and_value* getWorstCaseBinarySearch(int size);

array_and_value* getAverageCaseSearch(int size);

#endif