#include "../include/algorithm.h"
#include <stdlib.h>
#include <time.h>

//
// Private
//

static int* getFilledArray(int size){
    int* array = malloc(size * sizeof(int));
    for(int i=0; i<size; i++){
        array[i] = i;
    }
}

static int* shuffleArray(int* array, int size){
    // Seed the random number generator
    srand(time(NULL));

    for (int i=size-1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    return array;
}


//
// Public
//


int* getBestCaseBubbleSort(int size){
    int* array = getSortedAscendingArray(size);
    return array;
}

int* getWorstCaseBubbleSort(int size){
    int* array = getSortedDescendingArray(size);
    return array;
}


int* getBestCaseInsertionSort(int size){
    int* array = getSortedAscendingArray(size);
    return array;
}


int* getWorstCaseInsertionSort(int size){
    int* array = getSortedDescendingArray(size);
    return array;
}


int* getBestCaseQuickSortHigh(int size){

}


int* getWorstCaseQuickSortHigh(int size){
    int* array = getSortedAscendingArray(size);
    return array;
}

int* getSortedAscendingArray(int size){
    int* array = getFilledArray(size);
    return array;
}

int* getSortedDescendingArray(int size){
    int* array = getFilledArray(size);
    bubble_sort_descending(array, size);
    return array;
}

int* getRandomizedArray(int size){
    int* array = getFilledArray(size);
    shuffleArray(array, size);
    return array;
}